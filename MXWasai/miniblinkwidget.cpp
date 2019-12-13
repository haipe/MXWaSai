#include "miniblinkwidget.h"




// 回调：点击了关闭、返回 true 将销毁窗口，返回 false 什么都不做。
bool HandleWindowClosing(wkeWebView webWindow, void* param)
{
    return true;
}

// 回调：窗口已销毁
void HandleWindowDestroy(wkeWebView webWindow, void* param)
{
    //PostQuitMessage(0);
}

// 回调：文档加载成功
void HandleDocumentReady(wkeWebView webWindow, void* param)
{
    wkeShowWindow(webWindow, TRUE);
}

// 回调：页面标题改变
void HandleTitleChanged(wkeWebView webWindow, void* param, const wkeString title)
{
    wkeSetWindowTitle(webWindow, wkeGetString(title));
}

// 回调：创建新的页面，比如说调用了 window.open 或者点击了 <a target="_blank" .../>
wkeWebView HandleCreateView(wkeWebView webWindow, void* param, wkeNavigationType navType, const wkeString url, const wkeWindowFeatures* features)
{
    //wkeWebView newWindow = wkeCreateWebWindow(WKE_WINDOW_TYPE_POPUP, NULL, features->x, features->y, features->width, features->height);
    //wkeShowWindow(newWindow, true);
    return nullptr;
}

bool HandleLoadUrlBegin(wkeWebView webView, void* param, const char *url, void *job)
{
    return true;
}

void HandleLoadUrlEnd(wkeWebView webView, void* param, const char *url, void *job, void* buf, int len)
{
    return ;
}


MiniBlinkWidget::MiniBlinkWidget(QWidget *parent) : QWidget(parent)
{
    HWND wnd = (HWND)QWidget::winId();

    ////wkeCreateWebWindow(WKE_WINDOW_TYPE_TRANSPARENT, NULL, 0, 0, 640, 480);
    wkeWebView wenView = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, wnd, 0, 0, 640, 480);
    if (wenView)
    {
        wkeOnWindowClosing(wenView, HandleWindowClosing, this);
        wkeOnWindowDestroy(wenView, HandleWindowDestroy, this);
        wkeOnDocumentReady(wenView, HandleDocumentReady, this);
        wkeOnTitleChanged(wenView, HandleTitleChanged, this);
        wkeOnCreateView(wenView, HandleCreateView, this);
        wkeOnLoadUrlBegin(wenView, HandleLoadUrlBegin, this);
        wkeOnLoadUrlEnd(wenView, HandleLoadUrlEnd, this);

        web_view = wenView;

        //wkeMoveToCenter(wenView);

        QString path = "file:///" + QCoreApplication::applicationDirPath() + "/Web/index.html";
        wkeLoadURL(wenView, path.toLocal8Bit());
    }
}

void MiniBlinkWidget::wkeInit()
{
    if(!wkeIsInitialize || !wkeIsInitialize())
        ::wkeInitialize();
}

void MiniBlinkWidget::wkeFinal()
{
    if(wkeIsInitialize && wkeIsInitialize())
        wkeFinalize();
}

void MiniBlinkWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if(web_view)
    {
        wkeResize(web_view,event->size().width(),event->size().height());
    }
}
