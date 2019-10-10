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
    setSize (500, 394);
   
	//Dial Implimentation

    //filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
	filterCutoffDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	filterCutoffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	filterCutoffDial.setSize(80, 80);
	

	filterResDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	filterResDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	filterResDial.setSize(50, 50);
	

	//filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
	filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "cutoff", filterCutoffDial);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "resonance", filterResDial);
    
    //addAndMakeVisible(filterCutoffLabel);
    // filterCutoffLabel.setText("Cutoff Freq", dontSendNotification);
    mixLabel.attachToComponent(&filterCutoffDial, false);
    
    addAndMakeVisible(filterResLabel);
    //filterResLabel.setText("Q", dontSendNotification);
    filterResLabel.attachToComponent(&filterResDial, false);
    
    
    delayTimeDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayTimeDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    delayTimeDial.setNumDecimalPlacesToDisplay(0);
    delayTimeDial.setSize(67, 67);
    delayTimeDial.setTextValueSuffix("ms");
    
	//delayTimeDial.addListener(this);
    addAndMakeVisible(delayTimeDial);
    
    delayMixDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayMixDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    delayMixDial.setSize(67, 67);
	//delayMixDial.addListener(this);
    addAndMakeVisible(delayMixDial);
    
    delayFeedbackDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    delayFeedbackDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    delayFeedbackDial.setNumDecimalPlacesToDisplay(0);
    delayFeedbackDial.setSize(67, 67);
    delayFeedbackDial.setTextValueSuffix("ms");
    
	//delayFeedbackDial.addListener(this);
	addAndMakeVisible(delayFeedbackDial);

	//Skinning the Dials by connecting them to classes established in the PluginEditor.h 
	filterCutoffDial.setLookAndFeel(&otherLookAndFeel);
	filterResDial.setLookAndFeel(&otherLookAndFeel3);
    delayTimeDial.setLookAndFeel(&otherLookAndFeel);
    delayMixDial.setLookAndFeel(&otherLookAndFeel);
    delayFeedbackDial.setLookAndFeel(&otherLookAndFeel);

    
    delayTimeValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "delayTime", delayTimeDial);
    delayMixValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "mix", delayMixDial);
    delayFeedbackValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "feedback", delayFeedbackDial);
    
    
}

InitialDelayAudioProcessorEditor::~InitialDelayAudioProcessorEditor()
{
}

//==============================================================================
void InitialDelayAudioProcessorEditor::paint (Graphics& g)
{
	Image background = ImageCache::getFromMemory(BinaryData::InitialD_png, BinaryData::InitialD_pngSize);
	g.drawImageAt(background, 0, 0);
}

void InitialDelayAudioProcessorEditor::resized()
{
	//Placement of dials on canvis 
	filterCutoffDial.setBounds(40, getHeight() - 107, 80, 80);
	filterResDial.setBounds(118, getHeight() - 107, 80, 80);
    
	delayTimeDial.setBounds(200, getHeight() - 99, 80, 80);
    delayFeedbackDial.setBounds(295, getHeight()- 99, 80, 80);
	delayMixDial.setBounds(390, getHeight() - 99, 80, 80);
}

