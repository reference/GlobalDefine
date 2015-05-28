//
//  GlobalDefine.h
//
//  Created by Scott Ban (https://github.com/reference) on 14/07/30.
//  Copyright (C) 2011-2020 by Scott Ban

//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef Community_GlobalDefine_h
#define Community_GlobalDefine_h

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

//判断是否为iphone6、iphone6p、iphone5
#define iphone6 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define iphone6p (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

//判断当前系统版本是否ios7
#define IOS7_OR_LATER	( [[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending )

//获得当前屏幕宽、高
#define ScreenWidth [[UIScreen mainScreen] bounds].size.width
#define ScreenHeight [[UIScreen mainScreen] bounds].size.height

#endif
