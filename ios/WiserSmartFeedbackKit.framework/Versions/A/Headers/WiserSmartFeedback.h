//
//  WiserSmartFeedback.h
//  WiserSmartKit
//
//
//  Copyright © 2016年 Wiser. All rights reserved.
//

#import <WiserSmartUtil/WiserSmartUtil.h>
#import "WiserSmartFeedbackTalkListModel.h"
#import "WiserSmartFeedbackModel.h"
#import "WiserSmartFeedbackTypeListModel.h"

@interface WiserSmartFeedback : NSObject


/**
 *  Get feedback session list.
 *  获取反馈会话列表
 *
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)getFeedbackTalkList:(void (^)(NSArray<WiserSmartFeedbackTalkListModel *> *list))success
                    failure:(WSFailureError)failure;


/**
 *  Get feedback list.
 *  获取反馈列表
 *
 *  @param hdId         Feedback Id
 *  @param hdType       Feedback type
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)getFeedbackList:(NSString *)hdId
                 hdType:(NSUInteger)hdType
                success:(void (^)(NSArray<WiserSmartFeedbackModel *> *list))success
                failure:(WSFailureError)failure;


/**
 *  Get feedback type list.
 *  获取反馈类型列表
 *
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)getFeedbackTypeList:(void (^)(NSArray<WiserSmartFeedbackTypeListModel *> *list))success
                    failure:(WSFailureError)failure;


/**
 *  Submit feedback.
 *  添加反馈
 *
 *  @param content      Feedback content
 *  @param hdId         Feedback Id
 *  @param hdType       Feedback type
 *  @param contact      Contact
 *  @param success      Success block
 *  @param failure      Failure block
 */
- (void)addFeedback:(NSString *)content
               hdId:(NSString *)hdId
             hdType:(NSUInteger)hdType
            contact:(NSString *)contact
            success:(WSSuccessHandler)success
            failure:(WSFailureError)failure;


/**
 *  Cancel the request being executed.
 *  取消正在进行的操作
 */
- (void)cancelRequest;


@end
