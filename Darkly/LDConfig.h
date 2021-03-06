//
//  Copyright © 2015 Catamorphic Co. All rights reserved.
//

@interface LDConfig : NSObject {
    
}

@property (nonatomic) NSString* apiKey;
@property (nonatomic) NSString* baseUrl;
@property (nonatomic) NSNumber* capacity;
@property (nonatomic) NSNumber* connectionTimeout;
@property (nonatomic) NSNumber* flushInterval;
@property (nonatomic) BOOL debugEnabled;

@end

@interface LDConfigBuilder : NSObject {
    
}

/**
 * Provide an apiKey to the configuration builder. This is the apiKey
 * retrieved from the Launch Darkly account settings. (Required)
 *
 * @param apiKey    the apiKey for the configuration
 * @return the configuration builder
 */
- (LDConfigBuilder *)withApiKey:(NSString *)apiKey;
/**
 * Provide the baseUrl of the Launch Darkly server. This will allow you
 * to switch between production and staging environments. (Optional)
 *
 * @param baseUrl    the baseUrl of the server
 * @return the configuration builder
 */
- (LDConfigBuilder *)withBaseUrl:(NSString *)baseUrl;
/**
 * Provide the capacity for storing feature flag and custom events. Events
 * are persisted on the client and then synced to the server on a regular 
 * basis. If there is ever a prolonged period of time between the last server
 * sync, the capacity defined here will determine at what points the events
 * are ignored and no longer stored. The default is 100. (Optional)
 *
 * @param capacity  the number of events to store
 * @return the configuration builder
 */
- (LDConfigBuilder *)withCapacity:(int)capacity;
/**
 * The connection timeout to be used when syncing to the Launch Darkly 
 * server. The default is 10 seconds. (Optional)
 *
 * @param connectionTimeout timeout for network connections in seconds
 * @return the configuration builder
 */
- (LDConfigBuilder *)withConnectionTimeout:(int)connectionTimeout;
/**
 * The interval at which events are synced to the server. The default
 * is 30 seconds. (Optional)
 *
 * @param flushInverval the flush interval in seconds
 * @return the configuration builder
 */
- (LDConfigBuilder *)withFlushInterval:(int)flushInterval;
/**
 * Enable debug mode to allow things such as logging. (Optional)
 *
 * @return the configuration builder
 */
- (LDConfigBuilder *)withDebugEnabled:(BOOL)debugEnabled;

-(LDConfig *)build;

@end
