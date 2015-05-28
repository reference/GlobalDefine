//
//  GlobalDefine.h
//  Community
//
//  Created by Scott Ban on 15/5/28.
//  Copyright (c) 2015年 ios. All rights reserved.
//

#ifndef Community_GlobalDefine_h
#define Community_GlobalDefine_h

/************************************/
#pragma mark - 转圈
#pragma mark -

#define Spining_Hide_Wait   @"Spining_Hide_Wait"
#define Spining_Show_Wait   @"Spining_Show_Wait"

#define Network_Fail        @"Network_Fail"

/************************************/
#pragma mark - 通知监听、移除
#pragma mark -

#define ObserverNotificationByName(NAME) [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(handleNotification:) name:NAME object:nil];
#define RemoveNotificationByName(NAME) [[NSNotificationCenter defaultCenter] removeObserver:self name:NAME object:nil];
#define PostNotificationByName(NAME,OBJECT)[[NSNotificationCenter defaultCenter]postNotificationName:NAME object:OBJECT];

/************************************/
#pragma mark - 日志打印
#pragma mark -

#ifndef LLog
//#define LLogF(format, ...) NSLog(@"%s:%i: %@", __FILE__, __LINE__, [NSString stringWithFormat:format, ##__VA_ARGS__]);
#define LLogF(format, ...) NSLog(@"%@", [NSString stringWithFormat:format, ##__VA_ARGS__]);

#ifdef DEBUG
#define LLog(format, ...) LLogF(format, ##__VA_ARGS__);
#else
#define LLog(format, ...) while(0){}
#endif
#endif

/************************************/
#pragma mark - 设备参数相关
#pragma mark -

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

//获得当前屏幕宽、高
#define ScreenWidth [[UIScreen mainScreen] bounds].size.width
#define ScreenHeight [[UIScreen mainScreen] bounds].size.height

//判断是否为iphone6、iphone6p、iphone5
#define iphone6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define iphone6p (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

//判断当前系统版本是否ios7
#define IOS7_OR_LATER	( [[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending )

/************************************/
#pragma mark - 服务器
#pragma mark -

//返回服务器地址
#define HostUrl [[BusinessURL Instance] getURLWithRequest:URL_Host]

/************************************/
#pragma mark - 缓存
#pragma mark -

//缓存归档文件夹
#define CacheDirectory @"CacheData"

/************************************/
#pragma mark - 扩展方法
#pragma mark -

//转换色值为uicolor
#define UICOLOR_RGB_Alpha(_color,_alpha) [UIColor colorWithRed:((_color>>16)&0xff)/255.0f green:((_color>>8)&0xff)/255.0f blue:(_color&0xff)/255.0f alpha:_alpha]

#endif
