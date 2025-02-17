/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
Copyright (c) 2021-2023 Bytedance Inc.

https://axmolengine.github.io/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CCDEVICE_H__
#define __CCDEVICE_H__

#include "platform/PlatformMacros.h"
#include "base/Macros.h"
#include "base/Data.h"

NS_AX_BEGIN

struct FontDefinition;

/**
 * @addtogroup platform
 * @{
 */

/**
 * @class Device
 * @brief
 */
class AX_DLL Device
{
public:
    /** Defines the alignment of text. */
    enum class TextAlign
    {
        CENTER       = 0x33, /** Horizontal center and vertical center. */
        TOP          = 0x13, /** Horizontal center and vertical top. */
        TOP_RIGHT    = 0x12, /** Horizontal right and vertical top. */
        RIGHT        = 0x32, /** Horizontal right and vertical center. */
        BOTTOM_RIGHT = 0x22, /** Horizontal right and vertical bottom. */
        BOTTOM       = 0x23, /** Horizontal center and vertical bottom. */
        BOTTOM_LEFT  = 0x21, /** Horizontal left and vertical bottom. */
        LEFT         = 0x31, /** Horizontal left and vertical center. */
        TOP_LEFT     = 0x11, /** Horizontal left and vertical top. */
    };

    /** Defines the impact haptic feedback style. */
    enum ImpactFeedbackStyle
    {
        ImpactFeedbackStyleLight = 0,
        ImpactFeedbackStyleMedium,
        ImpactFeedbackStyleHeavy
    };

    /** Defines the notification haptic feedback style. */
    enum NotificationFeedbackType
    {
        NotificationFeedbackTypeSuccess = 0,
        NotificationFeedbackTypeWarning,
        NotificationFeedbackTypeError
    };

    /**
     *  Gets the DPI of device
     *  @return The DPI of device.
     */
    static int getDPI();
    
    /**
     * Gets the device pixel ratio
     */
    static float getPixelRatio();

    /**
     * To enable or disable accelerometer.
     */
    static void setAccelerometerEnabled(bool isEnabled);

    /**
     *  Sets the interval of accelerometer.
     */
    static void setAccelerometerInterval(float interval);

    /**
     * Controls whether the screen should remain on.
     *
     * @param keepScreenOn One flag indicating that the screen should remain on.
     */
    static void setKeepScreenOn(bool keepScreenOn);

    /**
     * Vibrate for the specified amount of time.
     * If vibrate is not supported, then invoking this method has no effect.
     * Some platforms limit to a maximum duration of 5 seconds.
     * Duration is ignored on iOS due to API limitations.
     * @param duration The duration in seconds.
     */
    static void vibrate(float duration);

    /**
     * Prepare haptic feedback impact with selected style
     * If haptic feedback is not supported, then invoking this method has no effect.
     * @param style The style of the feedback.
     */
    static void prepareImpactFeedbackGenerator(ImpactFeedbackStyle style);

    /**
     * Generate haptic feedback impact with selected style
     * If haptic feedback is not supported, then invoking this method has no effect.
     */
    static void impactOccurred(ImpactFeedbackStyle style);

    /**
     * Prepare haptic feedback notification
     * If haptic feedback is not supported, then invoking this method has no effect.
     * @param style The style of the feedback.
     */
    static void prepareNotificationFeedbackGenerator();

    /**
     * Generate haptic feedback notification with selected type
     * If haptic feedback is not supported, then invoking this method has no effect.
     */
    static void notificationOccurred(NotificationFeedbackType type);

    /**
     * Prepare haptic feedback selection
     * If haptic feedback is not supported, then invoking this method has no effect.
     * @param style The style of the feedback.
     */
    static void prepareSelectionFeedbackGenerator();

    /**
     * Generate haptic feedback selection changed
     * If haptic feedback is not supported, then invoking this method has no effect.
     */
    static void selectionChanged();

    /**
     * Gets texture data for text.
     */
    static Data getTextureDataForText(std::string_view text,
                                      const FontDefinition& textDefinition,
                                      TextAlign align,
                                      int& width,
                                      int& height,
                                      bool& hasPremultipliedAlpha);

private:
    AX_DISALLOW_IMPLICIT_CONSTRUCTORS(Device);
};

// end group
/// @}

NS_AX_END

#endif /* __CCDEVICE_H__ */
