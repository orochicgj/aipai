//#import “record.h”
//#import <Foundation/Foundation.h>
#import <AiPaiSDK/APSharePlusC.h>

/**
 *  初始化
 *
 *  @param appKey    爱拍SDK的appKey
 *  @param weixinKey 微信分享的key
 *  @param qqZoneKey QQ空间分享的key
 */
void IsetUpWithAppKey(const char *appKey, const char *weixinKey, const char *qqZoneKey){
    setUpWithAppKey(appKey, weixinKey, qqZoneKey);
}

/**
 *  是否支持SDK
 *
 *  @return 是否支持SDK
 */
BOOL IisSupported(){
    return isSupported();
}

/**
 *  是否录制中
 *
 *  @return 是否录制中
 */
BOOL IisRecording(){
    return isRecording();
}

/**
 *  是否暂停
 *
 *  @return 是否暂停
 */
BOOL IisPaused(){
    return isPaused();
}

/**
 *  启动录制
 */
void IstartRecording(){
    startRecording();
}

/**
 *  停止录制
 */
void IstopRecording(){
    stopRecording();
}

/**
 *  暂停录制
 */
void IpauseRecording(){
    pauseRecording();
}

/**
 *  继续录制
 */
void IresumeRecording(){
    resumeRecording();
}

/**
 *  显示或隐藏控制工具件
 *
 *  @param show YES:显示; NO:隐藏
 */
void IshowControl(BOOL show){
    showControl(show);
}

/**
 *  显示本地作品库
 */
void IshowLibraryView(){
    showLibraryView();
}

/**
 *  显示Web作品库
 */
void IshowWebLibraryView(){
    showWebLibraryView();
}