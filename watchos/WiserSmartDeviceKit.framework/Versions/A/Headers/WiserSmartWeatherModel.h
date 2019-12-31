//
//  WiserSmartWeatherModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartWeatherModel : NSObject

@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *unit;
@property (nonatomic, assign) long long objId;
@property (nonatomic, assign) BOOL show;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, copy) NSString *metaValue;
@property (nonatomic, copy) NSString *fieldName;
@property (nonatomic, copy) NSString *roomName;

@end

NS_ASSUME_NONNULL_END
