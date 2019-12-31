//
//  WiserSmartWeatherSketchModel.h
//  Bolts
//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WiserSmartWeatherSketchModel : NSObject

@property (nonatomic, strong) NSString *condition;
@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *inIconUrl;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *mark;
@property (nonatomic, strong) NSString *temp;

@end

NS_ASSUME_NONNULL_END
