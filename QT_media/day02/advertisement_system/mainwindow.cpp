#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::count = 0;


void MainWindow::ad_vedio()
{
    if(ad_video_Process.state() == QProcess::Running)
    {
        ad_video_Process.kill();
        ad_video_Process.waitForFinished();
    }

    QString cmd = QString("mplayer -slave -quiet "
                          "-geometry 0:0 -zoom -x %1 -y %2 "
                          "/zero/Manchester.mp4")
            .arg(ui->ad_vediolabel->width())
            .arg(ui->ad_vediolabel->height());
    qDebug() << "cmd = " << cmd;

    ad_video_Process.start(cmd);
}

void MainWindow::show_time()
{
    QTime time = QTime::currentTime();
    ui->time_label->setText(time.toString("hh:mm:ss"));
    QDate date = QDate::currentDate();
    ui->date_label->setText(date.toString("yyyy-MM-dd"));
}

void MainWindow::show_ad_text()
{
//    update();
//    m_curIndex++;
//    if (m_curIndex*m_charWidth > width())
//        m_curIndex = 0;
    // 当截取的位置比字符串长时，从头开始
    if (count > sl.length())
        count = 0;

    ui->ad_text_label->setText(sl.mid(count));

// 闪动文字
//    ui->ad_text_label->setText(sl[count%3]);
    count++;
}

void MainWindow::read_data(QNetworkReply* reply)
{
    QByteArray array = reply->readAll();
    qDebug() << array;
    QJsonDocument doc = QJsonDocument::fromJson(array);

    //
    QJsonObject object =  doc.object();
    QJsonObject resultObject = object.value("result").toObject();
    QJsonObject todayObject = resultObject.value("today").toObject();
    QString mtemperature = todayObject.value("temperature").toString();
    QString mweather = todayObject.value("weather").toString();
    QString mcity = todayObject.value("city").toString();


    /*
{
    "resultcode":"200",
    "reason":"successed!",
    "result":{
        "sk":{
            "temp":"30",
            "wind_direction":"东南风",
            "wind_strength":"3级",
            "humidity":"63%",
            "time":"21:03"
        },
        "today":{
            "temperature":"28℃~35℃",
            "weather":"多云转晴",
            "weather_id":{
                "fa":"01",
                "fb":"00"
            },
            "wind":"持续无风向微风",
            "week":"星期三",
            "city":"广州",
            "date_y":"2020年07月22日",
            "dressing_index":"炎热",
            "dressing_advice":"天气炎热，建议着短衫、短裙、短裤、薄型T恤衫等清凉夏季服装。",
            "uv_index":"中等",
            "comfort_index":"",
            "wash_index":"较适宜",
            "travel_index":"较适宜",
            "exercise_index":"较适宜",
            "drying_index":""
        }}
    */


    ui->address_label->setText(mcity);
    ui->weather_label->setText(mweather);
    ui->tempreaturelabel->setText(mtemperature);
}

QString MainWindow::showText() const
{
    return m_showText;
}

void MainWindow::run_time()
{
    mtimer = new QTimer(this);
    connect(mtimer,&QTimer::timeout,this,&MainWindow::show_time);
    mtimer->setInterval(1000);
    mtimer->start(1000);
}

void MainWindow::ad_text()
{
    m_curIndex = 0;//当前文字下标值
    m_showText = tr("Welcome to the image processing software of Star Dragon Company");//显示的文字
    m_charWidth = fontMetrics().width("a");//每个字符的宽度

    mtimer = new QTimer(this);
    connect(mtimer,&QTimer::timeout,this,&MainWindow::show_ad_text);
    mtimer->setInterval(1000);
    mtimer->start(1000);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPen pen;
    pen.setColor(QColor(255,0,255));

    pen.setStyle(Qt::DashDotDotLine);

    QFont font("楷体",14,QFont::Bold);


    QPainter painter(this);
    painter.setPen(pen);

    painter.setFont(font);
    painter.drawText(0, 15, m_showText.mid(m_curIndex));
    painter.drawText(width() - m_charWidth*m_curIndex, 15, m_showText.left(m_curIndex));
}

void MainWindow::http_weather()
{
    manager = new QNetworkAccessManager();

    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::read_data);

    QUrl url("http://v.juhe.cn/weather/index?"
             "cityname=%E5%B9%BF%E5%B7%9E&dtype=&format="
             "&key=ca5fee35da9262336b26530ca0e76710");
    QNetworkRequest request(url);
    manager->get(request);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //播放视频广告
    ad_vedio();

    //显示时间
    run_time();

//    //创建线程池
//    QThreadPool *manager = QThreadPool::globalInstance();
//    //创建任务一
//    MyClock* mc = new MyClock();
//    //加入线程池并启动
//    manager->start(mc);

    //显示广告标语
    ad_text();

    // 天气API已连接成功
//    http_weather();
    QImage img;
    img.load(":/new/prefix1/weather/sunny.png");
    QPixmap originalPixmap = QPixmap::fromImage(img);
    ui->label->setPixmap(originalPixmap.scaled(ui->label->size(),
                         Qt::IgnoreAspectRatio,
                         Qt::SmoothTransformation));


}

MainWindow::~MainWindow()
{
    delete ui;
}


