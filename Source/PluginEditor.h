/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::red);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centreX, centreY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(-5.0f, -radius, 10.0f, radius * 0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
        
    }
    
};

class OtherLookAndFeel2 : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::yellowgreen);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centreX, centreY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(-5.0f, -radius, 10.0f, radius * 0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
        
    }
    
};

class OtherLookAndFeel3 : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::orangered);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centreX, centreY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(-3.0f, -radius, 6.0f, radius * 0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
        
    }
    
};

class InitialDelayAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    InitialDelayAudioProcessorEditor (InitialDelayAudioProcessor&);
    ~InitialDelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    
    juce::Image backGround;
    
    OtherLookAndFeel otherLookAndFeel;
    OtherLookAndFeel2 otherLookAndFeel2;
    OtherLookAndFeel3 otherLookAndFeel3;
    
    Slider filterCutoffDial;
    Slider filterResDial;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    
    Label filterCutoffLabel;
    Label filterResLabel;
    
    Slider delayTimeDial;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> delayTimeValue;
    Label delayTimeLabel;
    
 //   Slider delayEnablerDial;
//    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> delayEnablerValue;
//    Label delayEnablerLabel;
    
   // ShapeButton delayEnablerButton;
    //std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> delayEnableAttachment;
  //  ScopedPointer<AudioProcessorValueTreeState::ButtonAttachment> delayEnableValue;
    
    Slider mixSlider;
    Label mixLabel;
    
    Slider delayMixDial;
    Slider delayFeedbackDial;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> delayMixValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> delayFeedbackValue;
    
    Label delayMixLabel;
    Label delayFeedbackLabel;
    
    
    
 //   std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
    
 //   void sliderValueChanged(Slider * slider) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    InitialDelayAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InitialDelayAudioProcessorEditor)
};
