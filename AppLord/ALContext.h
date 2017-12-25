//
//  ALContext.h
//  AppLord
//
//  Created by fengnianji on 15/11/9.
//  Copyright © 2015年 cnbluebox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ALModule, ALService;
@interface ALContext : NSObject

/**
 *  Get the singletion
 */
+ (instancetype)sharedContext;

- (void)setUp;

@end

@interface ALContext (Launcher)

- (void)setLaunchTasks:(NSArray<NSString *> *)launchTasks idleTasks:(NSArray<NSString *> *)idleTasks;

/**
 *  launch
 */
- (void)launch;

@end

@interface ALContext (Service)

/**
 *  Register a dynamic service with it's implement class.
 *  other wise, use @AppLordService()
 */
- (void)registerService:(Protocol *)proto withImpl:(Class)implClass;

/**
 *  Find the service implement of the protocol, return nil if not registered, create instance
 *  if not create
 */
- (__nullable id)findService:(Protocol *)serviceProtocol;

/**
 *  Just like `findService`, but you can pass a service's class name
 */
- (__nullable id)findServiceByName:(NSString *)name;

/**
 *  Figure out if a service is registered
 */
- (BOOL)existService:(NSString *)serviceName;


@end


@interface ALContext (Module)

/**
 *  init a module
 */
- (void)loadModule:(Class)moduleClass;

/**
 *  Find the module instance
 */
- (__nullable id)findModule:(Class)moduleClass;

/**
 *  Find the module instance
 */
- (__nullable id)findModuleByName:(NSString *)moduleName;

@end

@interface ALContext (BackgroundTasks)

/**
 *  the max concurrent of default operation queue
 */
@property (nonatomic, assign) NSInteger maxConcurrentOperationCount;

/**
 *  batch run tasks, async on current thread.
 */
- (void)addAsyncTasks:(NSArray<NSOperation *> *)tasks;

/**
 *  add a task in the default background operation queue.
 */
- (void)addTask:(NSOperation *)task;

@end

@interface ALContext (Object)

- (void)setObject:(id _Nonnull)value forKey:(NSString *)key;
- (nullable id)objectForKey:(NSString *)key;

- (nullable NSString *)stringForKey:(NSString *)key;
- (nullable NSDictionary *)dictionaryForKey:(NSString *)key;
- (nullable NSArray *)arrayForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
