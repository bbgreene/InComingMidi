/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TutorialPluginIncomingMidiAudioProcessorEditor::TutorialPluginIncomingMidiAudioProcessorEditor (TutorialPluginIncomingMidiAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    
// these define the parameters of our slider object
   midiVolume.setSliderStyle (juce::Slider::LinearBarVertical);
   midiVolume.setRange (0.0, 127.0, 1.0);
   midiVolume.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
   midiVolume.setPopupDisplayEnabled (true, false, this);
   midiVolume.setTextValueSuffix (" Volume");
   midiVolume.setValue(1.0);

// this function adds the slider to the editor
    addAndMakeVisible (&midiVolume);
    midiVolume.addListener(this); // adding slider listner to volume slider
}

TutorialPluginIncomingMidiAudioProcessorEditor::~TutorialPluginIncomingMidiAudioProcessorEditor()
{
}

//==============================================================================
void TutorialPluginIncomingMidiAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void TutorialPluginIncomingMidiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // sets the position and size of the slider with arguments (x, y, width, height)
//    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
    midiVolume.setBounds (90, 30, 20, getHeight() - 60); // manual positioning
}

// inserting the listener function that sets our public processor volume variable
void TutorialPluginIncomingMidiAudioProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    audioProcessor.noteOnVel = midiVolume.getValue();
}

//test after name change
