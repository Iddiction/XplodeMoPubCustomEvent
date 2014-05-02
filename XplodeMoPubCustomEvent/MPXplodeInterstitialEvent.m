//
//  MPXplodeInterstitialEvent.m
//  XplodeMoPubDemo
//
//  Created by Jernej Strasner on 4/22/14.
//  Copyright (c) 2014 Iddiction. All rights reserved.
//

#import "MPXplodeInterstitialEvent.h"

@implementation MPXplodeInterstitialEvent {
	NSString *_breakpoint;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(promotionDidLoad:) name:XPLPromotionDidLoadNotification object:nil];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(promotionDidFailLoading:) name:XPLPromotionDidFailLoadingNotification object:nil];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(promotionWillOpen:) name:XPLPromotionWillOpenNotification object:nil];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(promotionDidOpen:) name:XPLPromotionDidOpenNotification object:nil];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(promotionWillClose:) name:XPLPromotionWillCloseNotification object:nil];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(promotionDidClose:) name:XPLPromotionDidCloseNotification object:nil];
    }
    return self;
}

- (void)requestInterstitialWithCustomEventInfo:(NSDictionary *)info
{
	_breakpoint = info[@"breakpoint"];
	if (!_breakpoint.length) {
		NSLog(@"[%@] [WARNING] You have to configure custom event data on the MoPub portal! Readme: https://github.com/Iddiction/XplodeMoPubCustomEvent", self.class);
		[self.delegate interstitialCustomEvent:self didFailToLoadAdWithError:nil];
	}
	else {
		[Xplode cachePromotionForBreakpoint:_breakpoint];
	}
}

- (void)showInterstitialFromRootViewController:(UIViewController *)rootViewController
{
	[Xplode presentPromotionForBreakpoint:_breakpoint onCompletion:nil];
}

- (void)dealloc
{
	[super dealloc];
	[[NSNotificationCenter defaultCenter] removeObserver:self];
}

#pragma mark - Xplode Promotion Notifications

- (void)promotionDidLoad:(NSNotification *)note
{
	NSString *breakp = note.userInfo[XPLPromotionNotificationBreakpointKey];
	if ([_breakpoint isEqualToString:breakp]) {
		[self.delegate interstitialCustomEvent:self didLoadAd:nil];
	}
}

- (void)promotionDidFailLoading:(NSNotification *)note
{
	NSString *breakp = note.userInfo[XPLPromotionNotificationBreakpointKey];
	if ([_breakpoint isEqualToString:breakp]) {
		[self.delegate interstitialCustomEvent:self didFailToLoadAdWithError:nil];
	}
}

- (void)promotionWillOpen:(NSNotification *)note
{
	NSString *breakp = note.userInfo[XPLPromotionNotificationBreakpointKey];
	if ([_breakpoint isEqualToString:breakp]) {
		[self.delegate interstitialCustomEventWillAppear:self];
	}
}

- (void)promotionDidOpen:(NSNotification *)note
{
	NSString *breakp = note.userInfo[XPLPromotionNotificationBreakpointKey];
	if ([_breakpoint isEqualToString:breakp]) {
		[self.delegate interstitialCustomEventDidAppear:self];
	}
}

- (void)promotionWillClose:(NSNotification *)note
{
	NSString *breakp = note.userInfo[XPLPromotionNotificationBreakpointKey];
	if ([_breakpoint isEqualToString:breakp]) {
		[self.delegate interstitialCustomEventWillDisappear:self];
	}
}

- (void)promotionDidClose:(NSNotification *)note
{
	NSString *breakp = note.userInfo[XPLPromotionNotificationBreakpointKey];
	if ([_breakpoint isEqualToString:breakp]) {
		[self.delegate interstitialCustomEventDidDisappear:self];
	}
}

@end
