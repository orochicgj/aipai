//
//  APSharePlus.h
//
//  Created by Zou Guangxian on 14-4-9.
//  Copyright (c) 2014年 AiPai. All rights reserved.
//

#import <Foundation/Foundation.h>

#define GetMediaFileAbsolutePath(x) [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"] stringByAppendingPathComponent:(x)]

// 界面显示通知
extern NSString *kAPViewsWillShowNotifacation;
extern NSString *kAPViewsDidShowNotifacation;

// 界面消失通知
extern NSString *kAPViewsWillDismissNotifacation;
extern NSString *kAPViewsDidDismissNotifacation;

// 录制启动与停止通知
extern NSString *kAPRecordStartNotifacation;
extern NSString *kAPRecordStopNotifacation; // userInfo contains NSNumber with did save video file or not

// 录制暂停与继续通知
extern NSString *kAPRecordPauseNotifacation;
extern NSString *kAPRecordResumeNotifacation;



@interface APSharePlus : NSObject

/**
 *  初始化
 *
 *  @param appKey    爱拍SDK的appKey
 *  @param weixinKey 微信分享的key
 *  @param qqZoneKey QQ空间分享的key
 */
+ (void)setUpWithAppKey:(NSString *)appKey
              weixinKey:(NSString *)weixinKey
              qqZoneKey:(NSString *)qqZoneKey;

/**
 *  是否支持SDK
 *
 *  @return 是否支持SDK
 */
+ (BOOL)isSupported;

/**
 *  是否录制中
 *
 *  @return 是否录制中
 */
+ (BOOL)isRecording;

/**
 *  是否暂停
 *
 *  @return 是否暂停
 */
+ (BOOL)isPaused;


#pragma mark - 操作控制
/**
 *  启动录制
 */
+ (void)startRecording;

/**
 *  停止录制
 */
+ (void)stopRecording;

/**
 *  暂停录制
 */
+ (void)pauseRecording;

/**
 *  继续录制
 */
+ (void)resumeRecording;


#pragma mark - UI
/**
 *  显示或隐藏控制工具件
 *
 *  @param show YES:显示; NO:隐藏
 */
+ (void)showControl:(BOOL)show;

/**
 *  显示本地作品库
 */
+ (void)showLibraryView;

/**
 *  显示Web作品库
 */
+ (void)showWebLibraryView;


#pragma mark - 分享
/**
 *  分享平台的回调处理实例: id<QQApiInterfaceDelegate, WXApiDelegate>
 */
+ (id)sharePlatformDelegate;

@end
