# Xplode Event Class for MoPub (iOS)

This project contains a custom event class for using Xplode with MoPub.

## Integration

1. Add the Xplode SDK to your project. You can download it [here](https://xplode.iddiction.com/#!sdk). The guide is included in the zip file.
2. Integrate the MoPub SDK by following their [integration instructions](https://github.com/mopub/mopub-ios-sdk).
3. Add the files `MPXplodeInterstitialEvent.h` and `MPXplodeInterstitialEvent.m` to your Xcode project.
4. Add Xplode as a new custom native network on the MoPub portal. When adding the network make sure you set `MPXplodeInterstitialEvent` as the *custom event class*. You also have to provide *custom event class data* as this is where you pass the breakpoint that you wish to call the promotion for. You can enter something like `{"breakpoint":"mopub"}`.
