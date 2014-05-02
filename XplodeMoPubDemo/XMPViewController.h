//
//  XMPViewController.h
//  XplodeMoPubDemo
//
//  Created by Jernej Strasner on 4/22/14.
//  Copyright (c) 2014 Iddiction. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MPInterstitialAdController.h"

@interface XMPViewController : UIViewController <MPInterstitialAdControllerDelegate>

@property (nonatomic, strong) MPInterstitialAdController *interstitial;

- (IBAction)showAd:(id)sender;

@end
