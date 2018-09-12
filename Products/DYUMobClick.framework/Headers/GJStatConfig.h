//
//  GJStatConfig.h
//  GJStat-SDK
//
//  Created by bellchen on 2017/2/10.
//  Copyright © 2017年 guojiang.tv. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, GJStatReportStrategy) {
    GJStat_STRATEGY_INSTANT = 1,            //实时上报
    GJStat_STRATEGY_BATCH = 2,              //批量上报，达到缓存临界值时触发发送
    GJStat_STRATEGY_APP_LAUNCH = 3,         //应用启动时发送
    GJStat_STRATEGY_ONLY_WIFI = 4,          //仅在WIFI网络下发送
    GJStat_STRATEGY_PERIOD = 5,             //每间隔一定最小时间发送，默认24小时
    GJStat_STRATEGY_DEVELOPER = 6,          //开发者在代码中主动调用发送行为
    GJStat_STRATEGY_ONLY_WIFI_NO_CACHE = 7  //仅在WIFI网络下发送, 发送失败以及非WIFI网络情况下不缓存数据
};
@interface GJStatConfig : NSObject
@property BOOL debugEnable;                     //debug开关
@property uint32_t sessionTimeoutSecs;          //Session超时时长，默认30秒
@property GJStatReportStrategy reportStrategy;    //统计上报策略
@property (nonatomic, copy) NSString* appkey; //应用的统计AppKey
@property (nonatomic, copy) NSString* channel;//渠道名，默认为"appstore"
@property uint32_t maxStoreEventCount;          //最大缓存的未发送的统计消息，默认1024
@property uint32_t maxLoadEventCount;           //一次最大加载未发送的缓存消息，默认30
@property uint32_t minBatchReportCount;         //统计上报策略为BATCH时，触发上报时最小缓存消息数，默认30
@property uint32_t maxSendRetryCount;           //发送失败最大重试数，默认3
@property uint32_t sendPeriodMinutes;           //上报策略为PERIOD时发送间隔，单位分钟，默认一天（1440分钟）
@property uint32_t maxParallelTimingEvents;     //最大并行统计的时长事件数，默认1024
@property BOOL  smartReporting;                 //智能上报开关：在WIFI模式下实时上报，默认TRUE
@property BOOL  autoExceptionCaught;            //智能捕获未catch的异常，默认TRUE；设置为False需要在startWithAppkey前调用
@property uint32_t maxReportEventLength;        //最大上报的单条event长度，超过不上报
@property (nonatomic, copy) NSString* qq;           //QQ号或者帐号
@property (nonatomic, copy) NSString* account;      //帐号
@property int8_t accountType;                       //帐号类型
@property (nonatomic, copy) NSString* accountExt;   //帐号的扩展信息
@property BOOL statEnable;
//@property BOOL enableReportIDFA;               //是否上报IDFA，默认为NO，注意：苹果限制只有带广告的APP才能获取，开启前请确保符合要求67

@property (nonatomic, copy) NSString* customerUserID;
@property (nonatomic, copy) NSString* customerAppVersion;
@property (nonatomic, strong) NSDictionary *customerInfo;

@property (nonatomic, copy) NSString* statReportURL; //自定义的上报url
@property int32_t maxSessionStatReportCount;

@property (nonatomic,copy) NSString* op;          //运营商
@property (nonatomic,copy) NSString* cn;          //网络类型
@property (nonatomic,copy) NSString* sp;   //测速结果

-(id) init;
-(NSString*)getCustomProperty:(NSString*) key default:(NSString*) v;
+(id) getInstance;
@end
