//
//  APSharePlusC.h
//  APSharePlusSDK
//
//  Created by xiewei on 14-8-4.
//  Copyright (c) 2014年 AiPai. All rights reserved.
//

#ifndef _AP_SHAREPLUS_C_H
#define _AP_SHAREPLUS_C_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  初始化
 *
 *  @param appKey    爱拍SDK的appKey
 *  @param weixinKey 微信分享的key
 *  @param qqZoneKey QQ空间分享的key
 */
void setUpWithAppKey(const char *appKey, const char *weixinKey, const char *qqZoneKey);


    
/**
 *  是否支持SDK
 *
 *  @return 是否支持SDK
 */
BOOL isSupported();

/**
 *  是否录制中
 *
 *  @return 是否录制中
 */
BOOL isRecording();

/**
 *  是否暂停
 *
 *  @return 是否暂停
 */
BOOL isPaused();


#pragma mark - 操作控制
/**
 *  启动录制
 */
void startRecording();

/**
 *  停止录制
 */
void stopRecording();

/**
 *  暂停录制
 */
void pauseRecording();

/**
 *  继续录制
 */
void resumeRecording();


#pragma mark - UI相关
/**
 *  显示或隐藏控制工具件
 *
 *  @param show YES:显示; NO:隐藏
 */
void showControl(BOOL show);

/**
 *  显示本地作品库
 */
void showLibraryView();

/**
 *  显示Web作品库
 */
void showWebLibraryView();


#pragma mark - 分享
/**
 *  分享平台的回调处理实例: id<QQApiInterfaceDelegate, WXApiDelegate>
 */
void* sharePlatformDelegate();

#ifdef __cplusplus
}
#endif
#endif /* _AP_SHAREPLUS_C_H */