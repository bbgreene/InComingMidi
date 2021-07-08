/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TutorialPluginIncomingMidiAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener //added listener callback function
{
public:
    TutorialPluginIncomingMidiAudioProcessorEditor (TutorialPluginIncomingMidiAudioProcessor&);
    ~TutorialPluginIncomingMidiAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged (juce::Slider* slider) override; //added default callback function
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TutorialPluginIncomingMidiAudioProcessor& audioProcessor;

    juce::Slider midiVolume; // creating a new Slider object
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TutorialPluginIncomingMidiAudioProcessorEditor)
};
