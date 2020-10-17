//
//  WiserSmartSceneConditionModel.h
//  WiserSmartKit
//
//
//  Copyright © 2017年 Wiser. All rights reserved.
//

#import "WiserSmartSceneDPModel.h"

#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, WSSceneConditionStatus)
{
    WSSceneConditionStatusLoading = 0,
    WSSceneConditionStatusSuccess,
    WSSceneConditionStatusOffline,
    WSSceneConditionStatusTimeout,
};


typedef NS_ENUM(NSInteger, WSConditionAutoType)
{
    AutoTypeDevice = 1, //设备条件
    AutoTypeWhether = 3,    //天气条件
    AutoTypeTimer = 6,  //定时条件
    AutoTypePir = 7,    //人体传感器
    AutoTypeFaceRecognition = 9,    //人脸识别条件
    AutoTypeGeofence = 10,  //地理围栏条件
    AutoTypeLockMemberGoHome = 11,  //家人回家条件
    AutoTypeConditionCalculate = 13,    //设备合成功能条件计算,如某dp持续x小时
    AutoTypeSunsetriseTimer = 16,   //支持日出日落条件选择偏移量，日出前x分钟等
    AutoTypeManual = 99,    //“手动执行”条件，本地生成的条件。不保存到云端接口，云端接口也不会返回。 This type of condition should not be saved to server, and server will not return this type of conditon neither.
};


@interface WiserSmartSceneConditionModel : NSObject<NSCoding>

/**
 * 条件id
 * condition's Id.
 */
@property (nonatomic, copy) NSString *conditionId;

/**
 * 图标的url
 * iconUrl of the conditon's icon.
 */
@property (nonatomic, copy) NSString *iconUrl;

/**
 * 城市Id或设备id, 条件对应的实体的Id。
 * cityId if this condition is a meteorological condition, devId if this is a device condition, @"timer" if this is a timer condition.
 */
@property (nonatomic, copy) NSString *entityId;

/**
 * 城市或设备名称 如：“杭州市” 或 “智能插座”,定时条件设置为“定时”。
 * City name if this is a meteorological condition, device name if this is a device condition, @"timer" if this is a timer conditon.
 */
@property (nonatomic, copy) NSString *entityName;

/**
 * 实体类型，定时、设备类型（设备数据 = 1、气象数据 = 3、定时 = 6、pir人体传感器 = 7、地理围栏 = 10）
 * Entity's type, device as conditon it will be NSInteger 1, 3 for meteorological conditon, 6 for timer conditon, 7 for human body detector conditon, 10 for  geofencing conditon.
 */
@property (nonatomic, assign) WSConditionAutoType entityType;

/**
 * 条件显示内容，如: “湿度 : 舒适” 或 “开关 : 开启"
 * Description of conditon, like "Switch : Open","Humidity : Comfort"
 */
@property (nonatomic, copy) NSString *exprDisplay;

/**
 * 场景id, 可用来保存所属场景。
 * Scene's Id ,can be used to save the scene's Id which this action belonged to.
 */
@property (nonatomic, copy) NSString *scenarioId;

/**
 * 条件或设备的DP点id 如：“humidity” 或 “1”, 定时条件传"timer"。
 * Meteorological condition's subId or device's dpId, timer contion is "timer".
 */
@property (nonatomic, copy) NSString *entitySubIds;

/**
 * 条件表达式
 * 如：("$humidity","==","comfort") 或（“$dp1”，“==”，1）
 * 定时：{timeZoneId = "Asia/Shanghai",loops = "0000000",time = "08:00",date = "20180308"}
 * loops = "0000000"  表示 ： 周日周一周二周三周四周五周六
 * 详情参见文档:https://wiserinc.github.io/wisersmart_home_ios_sdk_doc/zh-hans/resource/SmartScene.html#%E5%8D%95%E4%B8%AA%E5%9C%BA%E6%99%AF%E6%93%8D%E4%BD%9C
 *
 * Condition's expression, like
 * ("$humidity","==","comfort") or（“$dp1”，“==”，1）
 * timer：{timeZoneId = "Asia/Shanghai",loops = "0000000",time = "08:00",date = "20180308"}
 * loops = "0000000" ,each bit representing from sunday to saturday.
 * Details in Doc: https://wiserinc.github.io/wisersmart_home_ios_sdk_doc/en/resource/SmartScene.html#smart-scene
 */
@property (nonatomic, strong) NSArray *expr;

/**
 * 条件状态
 * condition's status
 */
@property (nonatomic, assign) WSSceneConditionStatus status;

/**
 * 温度的单位,地理围栏详情等。{"tempUnit":"fahrenheit","Hangzhou City":"cityName"}，{"center":{"latitude":30.273173191721956,"longitude":120.09600875035049},"geotitle":"浙商财富中心B座","radius":180.00011311593616}}
 *
 * Unit of temprature, or geofence detail, {"tempUnit":"fahrenheit","Hangzhou City":"cityName"}，{"center":{"latitude":30.273173191721956,"longitude":120.09600875035049},"geotitle":"浙商财富中心B座","radius":180.00011311593616}}.
 */
@property (nonatomic, strong) NSDictionary *extraInfo;

/**
* 如果这个条件是设备类型条件，且此设备已从当前账号移除，此标记为YES。
* If this condition is a device type condition and this device has been removed from the current account, this flag is YES.
*/
@property (nonatomic, assign) BOOL devDelMark;

/**
* 如果这个条件是设备类型条件，且此设备已从当前账号移除，则提供此图标url用于展示设备图标。
* If this condition is a device type condition, and this device has been removed from the current account, then provide this icon url to display the device icon.
*/
@property (nonatomic, copy) NSString *deleteDevIcon;

/**
 * 城市名称
 * city name
 */
@property (nonatomic, copy) NSString *cityName;

@property (nonatomic, assign) CLLocationDegrees cityLatitude;

@property (nonatomic, assign) CLLocationDegrees cityLongitude;

#pragma mark - Recommend info

/**
* 推荐商品id。
* Recommend product id.
*/
@property (nonatomic, copy) NSString *productId;

/**
* 推荐商品图标。
* Recommend product icon.
*/
@property (nonatomic, copy) NSString *productPic;

@end
