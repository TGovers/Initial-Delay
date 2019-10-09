/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
InitialDelayAudioProcessorEditor::InitialDelayAudioProcessorEditor (InitialDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setSize (540, 450);
    
    filterCutoffDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    filterCutoffDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    filterCutoffDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterCutoffDial.setNumDecimalPlacesToDisplay(0);
    filterCutoffDial.setSize(150, 100);
    //filterCutoffDial.setRange(20.0, 20000.0);
    filterCutoffDial.setTextValueSuffix("hz");
    //filterCutoffDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    //filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
    filterResDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 50,30);
    filterResDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    filterResDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterResDial.setSize(150, 100);
    //filterResDial.setRange(1.0, 5.0);
    filterResDial.setTextValueSuffix("Q");
    //filterResDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    filterResDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    
    // dont change these two
    //filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
    // dont change these two
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "cutoff", filterCutoffDial);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "resonance", filterResDial);
    
    //filterCutoffDial.setSkewFactorFromMidPoint(1000.0f);
    
    filterCutoffDial.setLookAndFeel(&otherLookAndFeel);
    filterResDial.setLookAndFeel(&otherLookAndFeel);
    
    //addAndMakeVisible(filterCutoffLabel);
    // filterCutoffLabel.setText("Cutoff Freq", dontSendNotification);
    mixLabel.attachToComponent(&filterCutoffDial, false);
    
    addAndMakeVisible(filterResLabel);
    //filterResLabel.setText("Q", dontSendNotification);
    filterResLabel.attachToComponent(&filterResDial, false);
    
    
    delayTimeDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    delayTimeDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    delayTimeDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    delayTimeDial.setSliderStyle(Slider::SliderStyle::Rotary);
    delayTimeDial.setNumDecimalPlacesToDisplay(0);
    delayTimeDial.setSize(150, 100);
    delayTimeDial.setTextValueSuffix("ms");
    
 //   delayTimeDial.addListener(this);
    addAndMakeVisible(delayTimeDial);
    
    delayMixDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    delayMixDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    delayMixDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    delayMixDial.setSliderStyle(Slider::SliderStyle::Rotary);
    delayMixDial.setNumDecimalPlacesToDisplay(0);
    delayMixDial.setSize(150, 100);
    delayMixDial.setTextValueSuffix("ms");
    
  //  delayMixDial.addListener(this);
    addAndMakeVisible(delayMixDial);
    
    delayFeedbackDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    delayFeedbackDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    delayFeedbackDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    delayFeedbackDial.setSliderStyle(Slider::SliderStyle::Rotary);
    delayFeedbackDial.setNumDecimalPlacesToDisplay(0);
    delayFeedbackDial.setSize(150, 100);
    delayFeedbackDial.setTextValueSuffix("ms");
    
   // delayFeedbackDial.addListener(this);
    addAndMakeVisible(delayFeedbackDial);
    
    delayMixDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    delayMixDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    delayMixDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    delayMixDial.setSliderStyle(Slider::SliderStyle::Rotary);
    delayMixDial.setNumDecimalPlacesToDisplay(0);
    delayMixDial.setSize(150, 100);
    delayMixDial.setTextValueSuffix("ms");
    
    //delayMixDial.addListener(this);
    addAndMakeVisible(delayMixDial);
    
    /*
    delayEnablerDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    delayEnablerDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    delayEnablerDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    delayEnablerDial.setSliderStyle(Slider::SliderStyle::Rotary);
    delayEnablerDial.setNumDecimalPlacesToDisplay(0);
    delayEnablerDial.setSize(150, 100);
    delayEnablerDial.setTextValueSuffix("%");
    
    delayEnablerDial.addListener(this);
    addAndMakeVisible(delayEnablerDial);
    */
    
    /*
     Path shape;
     shape.addEllipse(0, 0, 50, 50);
     
     delayEnablerButton.setRadioGroupId(1);
     delayEnablerButton.setClickingTogglesState(true);
     delayEnablerButton.shouldUseOnColours(true);
     delayEnablerButton.setOnColours(Colours::darkslategrey, Colours::ivory, Colours::lightslategrey);
     delayEnablerButton.setShape(shape, true, true, true);
     //delayEnableAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(processor.mState, "delayEnable", delayEnablerButton));
     
     //delayEnablerButton.addListener(this);
     addAndMakeVisible(delayEnablerButton);
     */
    
    delayTimeDial.setLookAndFeel(&otherLookAndFeel3);
 //   delayEnablerDial.setLookAndFeel(&otherLookAndFeel3);
    delayMixDial.setLookAndFeel(&otherLookAndFeel);
    delayFeedbackDial.setLookAndFeel(&otherLookAndFeel2);
    
    delayTimeValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "delayTime", delayTimeDial);
//    delayEnablerValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "delayEnable", delayEnablerDial);
    //delayEnableValue = new AudioProcessorValueTreeState::ButtonAttachment (processor.mState, "delayEnable", delayEnablerButton);
    delayMixValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "mix", delayMixDial);
    delayFeedbackValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "feedback", delayFeedbackDial);
    
    
}

InitialDelayAudioProcessorEditor::~InitialDelayAudioProcessorEditor()
{
}

//==============================================================================
void InitialDelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
    //Image background = ImageCache::getFromMemory(BinaryData::ayaya7_png, BinaryData::ayaya7_pngSize);
    //g.drawImageAt(background, 0, 0);
    
    g.fillAll (Colours::darkorchid);
    
    // g.setColour (Colours::aqua);
    //g.setFont (15.0f);
    // g.drawFittedText ("GOVERSA2 PLUGIN", getLocalBounds(), Justification::centred, 1);
    
    g.setColour(Colours::black);
    g.setFont(Font ("Arial", 20.0f, Font::italic));
    //g.drawFittedText("Random Test Font! Hi There!", 10, 10, getWidth(), 50,
    //                 Justification::left, 1);
}

void InitialDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    filterCutoffDial.setBounds(25, getHeight() - 135, 80, 80);
	filterResDial.setBounds(125, getHeight() - 135, 80, 80);
    
    delayTimeDial.setBounds(0, getHeight()-280, 80, 80);
//    delayEnablerDial.setBounds(100, getHeight()- 280, 80, 80);
    //delayEnablerButton.setBounds(100, getHeight()- 280, 80, 80);
    delayMixDial.setBounds(100, getHeight()- 280, 80, 80);
    delayFeedbackDial.setBounds(200, getHeight()- 280, 80, 80);
    
    
}

/*void SeperatedDelayTestAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &mixSlider)
    {
        // dont change any of this void function
        // get the value on the current slider, pass to audio processor
        processor.mixLevel.setTargetValue(mixSlider.getValue());
        
    }
    
    if (slider == &filterCutoffDial)
     {
     
     // get the value on the current slider, pass to audio processor
     processor.freqLevel.setTargetValue(filterCutoffDial.getValue());
     
     }
     
     if (slider == &filterResDial)
     {
     
     // get the value on the current slider, pass to audio processor
     processor.resLevel.setTargetValue(filterResDial.getValue());
     
     }
    
}*/

