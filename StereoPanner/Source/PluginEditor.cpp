/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StereoPannerAudioProcessorEditor::StereoPannerAudioProcessorEditor (StereoPannerAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderPanPosition = new Slider ("new slider"));
    sliderPanPosition->setRange (-1, 1, 0);
    sliderPanPosition->setSliderStyle (Slider::Rotary);
    sliderPanPosition->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderPanPosition->addListener (this);

    addAndMakeVisible (togglePanMethod = new ToggleButton ("new toggle button"));
    togglePanMethod->setButtonText (TRANS("Linear / Constant Power"));
    togglePanMethod->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200); // Startstimer with interval of 200ms
    //[/Constructor]
}

StereoPannerAudioProcessorEditor::~StereoPannerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderPanPosition = nullptr;
    togglePanMethod = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StereoPannerAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StereoPannerAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderPanPosition->setBounds (120, 48, 152, 144);
    togglePanMethod->setBounds (120, 216, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StereoPannerAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderPanPosition)
    {
        //[UserSliderCode_sliderPanPosition] -- add your slider handling code here..
        processor.panPosition = sliderPanPosition->getValue();
        //[/UserSliderCode_sliderPanPosition]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void StereoPannerAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == togglePanMethod)
    {
        processor.togglePanMethod = togglePanMethod->getState();
        //[UserButtonCode_togglePanMethod] -- add your button handler code here..
        //[/UserButtonCode_togglePanMethod]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void StereoPannerAudioProcessorEditor::timerCallback()
{
    //exchange any data you want between UI elements and the plugin "ourProcessor"
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StereoPannerAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public timer"
                 constructorParams="StereoPannerAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="f048d56ea105c26e" memberName="sliderPanPosition"
          virtualName="" explicitFocusOrder="0" pos="120 48 152 144" min="-1"
          max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="71e149c4b6fceb68" memberName="togglePanMethod"
                virtualName="" explicitFocusOrder="0" pos="120 216 150 24" buttonText="Linear / Constant Power"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
