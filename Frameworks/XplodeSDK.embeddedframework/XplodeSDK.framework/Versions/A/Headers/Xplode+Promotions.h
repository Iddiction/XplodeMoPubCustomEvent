//
//  Xplode+Promotions.h
//  XplodeSDK
//
//  Created by Jernej Strasner on 10/16/12.
//  Copyright (c) 2012 Iddiction, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Xplode.h"

typedef NS_ENUM(NSInteger, XPLPromotionDockingPosition) {
	XPLPromotionDockingPositionBottom = 0,
	XPLPromotionDockingPositionTop
};

/* Preferences */

static NSString * const XPLPromotionPreferencesGridBackgroundOpacityKey			= @"IDDPromotionPreferencesGridBackgroundOpacity";
static NSString * const XPLPromotionPreferencesGridAppsFontColorKey				= @"IDDPromotionPreferencesGridAppsFontColor";

/* Notifications */

// The key in the user info dictionary which contains the breakpoint
static NSString * const XPLPromotionNotificationBreakpointKey					= @"com.iddiction.promotions.notification.key.breakpoint";

static NSString * const XPLPromotionWillOpenNotification						= @"com.iddiction.promotions.notification.willOpen";
static NSString * const XPLPromotionDidOpenNotification							= @"com.iddiction.promotions.notification.didOpen";
static NSString * const XPLPromotionWillCloseNotification						= @"com.iddiction.promotions.notification.willClose";
static NSString * const XPLPromotionDidCloseNotification						= @"com.iddiction.promotions.notification.didClose";
static NSString * const XPLPromotionWillLoadNotification						= @"com.iddiction.promotions.notification.willLoad";
static NSString * const XPLPromotionDidLoadNotification							= @"com.iddiction.promotions.notification.didLoad";
static NSString * const XPLPromotionDidFailLoadingNotification					= @"com.iddiction.promotions.notification.didFailLoading";

static NSString * const XPLPromotionWillShowDockNotification					= @"com.iddiction.promotions.notification.willShowDock";
static NSString * const XPLPromotionDidShowDockNotification						= @"com.iddiction.promotions.notification.didShowDock";
static NSString * const XPLPromotionWillHideDockNotification					= @"com.iddiction.promotions.notification.willHideDock";
static NSString * const XPLPromotionDidHideDockNotification						= @"com.iddiction.promotions.notification.didHideDock";

/// An object can conform to the XplodePromotionDelegate protocol in order to respond when promotions are loaded and presented.
@protocol XplodePromotionDelegate <NSObject>

@optional

//	Promotions

/// A promotion is about to open.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionWillOpenForBreakpoint:(NSString *)breakpoint;

/// A promotion's opening animation has finished.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionDidOpenForBreakpoint:(NSString *)breakpoint;

/// A promotion is about to close.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionWillCloseForBreakpoint:(NSString *)breakpoint;

/// A promotion's closing animation has finished.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionDidCloseForBreakpoint:(NSString *)breakpoint;

/// A promotion will start loading.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionWillLoadForBreakpoint:(NSString *)breakpoint;

/// A promotion finished loading.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionDidLoadForBreakpoint:(NSString *)breakpoint;

/// A promotion failed to load.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionDidFailLoadingForBreakpoint:(NSString *)breakpoint;

/// A promotion will show the dock.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionWillShowDockForBreakpoint:(NSString *)breakpoint;

/// A promotion did show the dock.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionDidShowDockForBreakpoint:(NSString *)breakpoint;

/// A promotion will hide the dock.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionWillHideDockForBreakpoint:(NSString *)breakpoint;

/// A promotion did hide the dock.
///
/// @param	breakpoint	The breakpoint of the promotion which caused this method to be called.
- (void)promotionDidHideDockForBreakpoint:(NSString *)breakpoint;

@end

@interface Xplode (Promotions)

/// Returns the promotion delegate.
///
/// Promotion delegates have to conform to the formal protocol XplodePromotionDelegate.
///
/// @return The promotion delegate.
+ (id<XplodePromotionDelegate>)promotionDelegate;

/// Sets the promotion delegate.
///
/// Promotion delegates have to conform to the formal protocol XplodePromotionDelegate.
///
///	@param delegate A promotion delegate.
+ (void)setPromotionDelegate:(id<XplodePromotionDelegate>)delegate;

/// Checks whether promotions are supported on the current device.
///
/// @return *YES* if the device is supported, *NO* otherwise.
+ (BOOL)isCurrentDeviceSupported;

/// Preloads the promotion for a specific breakpoint for presenting it later.
///
/// Nothing is presented on-screen, the data is only loaded from the server and cached.
///
///	@param breakpoint	Name of the breakpoint.
+ (void)cachePromotionForBreakpoint:(NSString *)breakpoint;

/// Presents a view controller with the promotion for the specified breakpoint.
/// When a promotion has been set up using setupPromotionDockForBreakpoint:atPosition:, this method only presents the loaded promotion.
///
///	@param breakpoint			Name of the breakpoint.
/// @param completionHandler	A completion block that is executed when the promotion is closed.
+ (void)presentPromotionForBreakpoint:(NSString *)breakpoint
						 onCompletion:(void(^)(void))completionHandler;

/// Checks if the promotion for the specified breakpoint is cached.
///
///	@param breakpoint	Name of the breakpoint.
///
/// @return *YES* if a promotion is cached for the specified breakpoint, *NO* otherwise.
+ (BOOL)isPromotionCachedForBreakpoint:(NSString *)breakpoint;

/// Returns a value whether any promotion is currently presented in full-screen.
///
/// The state changes when the presentAtBreakpoint:onCompletion:, dismissPromotion, removePromotionDock showPromotionDockAndBounce: and hidePromotionDock methods are called.
///
/// @return *YES* if open, *NO* if closed.
+ (BOOL)isPromotionOpen;

/// Returns the visibility of a dockable promotion. The promotion is visible if the dock is visible or if it is presented full-screen.
/// The state changes when the showPromotionDockAndBounce: and hidePromotionDock methods are called.
///
/// @note This method always returns *NO* when only a modal promotion is presented.
///
/// @return *YES* if visible, *NO* if hidden.
+ (BOOL)isPromotionDockVisible;

///	Initializes a dockable always-on-screen promotion for a specific breakpoint and optionally shows it at a specific position.
///
///	@param breakpoint      Name of the breakpoint.
///	@param dockingPosition Dock the promotion on bottom (default), or at top.
+ (void)setupPromotionDockForBreakpoint:(NSString *)breakpoint
							 atPosition:(XPLPromotionDockingPosition)dockingPosition;

///	Shows the promotion dock if a promotion has been set up as dockable.
/// If you call this method with bounce *YES* while the dock is already visible then only the bounce animation is performed.
///
/// @note The promotion dock can only be shown after the promotion has been set up using setupPromotionDockForBreakpoint:atPosition:.
///
///	@param bounce *YES* for bouncing animation, *NO* for sliding animation.
+ (void)showPromotionDockAndBounce:(BOOL)bounce;

/// Hides the promotion dock if a promotion has been set up as dockable.
///
/// @note The promotion dock can only be hidden after the promotion has been set up using setupPromotionDockForBreakpoint:atPosition: or shown using showPromotionDockAndBounce:.
+ (void)hidePromotionDock;

/// Dismisses the promotion dock and removes it from memory.
+ (void)removePromotionDock;

/// Dismisses any presented modal promotion and removes it from memory.
+ (void)dismissPromotion;

/// Optional. Sets allowed interface orientations for promotions.
///
/// If you want to disable certain orientations for different view controllers, call this method before presenting any promotions.
///
/// @note This method is optional.
///	@param allowedOrientations Allowed promotion orientations. For possible values, see Apple's UIApplication documentation about UIInterfaceOrientationMask.
+ (void)setAllowedPromotionOrientations:(UIInterfaceOrientationMask)allowedOrientations;

/// Use this method to set prefrences for the promotions.
/// The keys for the preferences that you can set are defined in the Xplode+Promotions.h file.
///
/// @param preferences An NSDictionary object with the prefrences. The object is copied.
+ (void)setPromotionPreferences:(NSDictionary *)preferences;

/// Returns the currently set preferences, if any.
+ (NSDictionary *)promotionPreferences;

@end