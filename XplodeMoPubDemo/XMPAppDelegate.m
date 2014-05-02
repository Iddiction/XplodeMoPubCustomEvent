//
//  XMPAppDelegate.m
//  XplodeMoPubDemo
//
//  Created by Jernej Strasner on 4/22/14.
//  Copyright (c) 2014 Iddiction. All rights reserved.
//

#import "XMPAppDelegate.h"

#import <XplodeSDK/XplodeSDK.h>

@implementation XMPAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	[Xplode initializeWithAppHandle:@"<#Your Xplode App Handle#>"
						  appSecret:@"<#Your Xplode App Secret#>"
					   onCompletion:nil];
	
    return YES;
}
							
@end
