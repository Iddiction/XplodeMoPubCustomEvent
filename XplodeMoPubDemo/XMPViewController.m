//
//  XMPViewController.m
//  XplodeMoPubDemo
//
//  Created by Jernej Strasner on 4/22/14.
//  Copyright (c) 2014 Iddiction. All rights reserved.
//

#import "XMPViewController.h"

@interface XMPViewController ()

@end

@implementation XMPViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

	self.interstitial = [MPInterstitialAdController interstitialAdControllerForAdUnitId:@"<#Yout Ad Unit ID#>"];
	self.interstitial.delegate = self;
	[self.interstitial loadAd];
}

- (IBAction)showAd:(id)sender
{
	[self.interstitial showFromViewController:self];
}

@end
