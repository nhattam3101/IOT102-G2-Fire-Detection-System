# AI AUDIT LOG

## IOT102 – IoT-Based Fire Detection and Warning System

**University:** FPT University  
**Semester:** Fall 2026  
**Course:** IOT102  
**Class:** SE2027  
**Group:** G2  
**Instructor:** Nguyễn Đức Lợi

### Team Members

|Student|Student ID|Main Responsibility|
|---|---|---|
|Hoàng Nhật Tâm|SE202018|Project coordination, research, report preparation|
|Phan Tấn Hùng|SE201027|Firmware development, sensor integration, debugging|
|Lê Võ Tuấn Kiệt|SE203376|Hardware assembly, wiring, prototype testing|

**AI tool used:** ChatGPT (OpenAI)

**Document purpose:** Record critical AI-assisted decisions, identify limitations or errors in AI-generated suggestions, describe student verification, and demonstrate independent engineering judgment.

**Evidence policy:** Only actual conversations, firmware, diagrams, documented research, and confirmed functional tests should be presented as evidence. Missing original prompts or experimental records must not be reconstructed as invented facts.

---

# PART I. DECOMPOSITION AND SYSTEM DESIGN

## Entry 001 – Defining the Project Scope

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Decomposition

**Problem / Context:** The project initially considered several possible IoT features, including fire detection, local alarms, automatic responses, and remote monitoring. The team needed to define a feasible prototype scope.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL PROMPT FROM THE INITIAL PROJECT-PLANNING CONVERSATION]

**AI Response (Summary):** ChatGPT discussed an architecture combining temperature, gas/smoke, and flame sensors with ESP32 processing, local warning devices, and possible Internet-based monitoring.

**Human Delta & Reflection**

- **Critical Thinking:** The proposed architecture contained more functions than the team had implemented. An architectural suggestion does not prove that each feature is operational.
    
- **Contextualization:** G2 had limited project time and needed a functional hardware prototype for IOT102.
    
- **Creative Synthesis:** The team focused on local fire detection, three warning states, LED/buzzer/LCD output, and servo-based door control.
    
- **Decision Ownership:** The implemented prototype was defined by its actual firmware and physical functions. Network features were treated separately as proposed extensions.
    

**Evidence:** Final firmware, project requirements, architecture documents.

**Verification Status:** Engineering decision supported; original prompt still needs retrieval.

---

## Entry 002 – Choosing a Multisensor Detection Architecture

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Decomposition / Abstraction

**Problem / Context:** A single sensor may react to environmental disturbances. The team needed to choose which sensing elements would be used.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL MULTISENSOR-SELECTION PROMPT]

**AI Response (Summary):** ChatGPT discussed combining temperature, flame, and gas/smoke sensing to obtain different indicators of a potentially dangerous condition.

**Human Delta & Reflection**

- **Critical Thinking:** Integrating three sensors does not automatically guarantee higher detection accuracy or fewer false alarms.
    
- **Contextualization:** The available prototype used an LM35, an MQ-2 module, and a flame sensor.
    
- **Creative Synthesis:** The team integrated one analog temperature input and two digital detection inputs into the ESP32.
    
- **Decision Ownership:** A three-sensor arrangement was retained because it covered different observable indicators while remaining feasible for the prototype.
    

**Evidence:** Hardware list, GPIO mapping, final firmware.

**Verification Status:** Supported by implementation; original prompt pending.

---

## Entry 003 – Separating Implemented and Planned IoT Features

**Prompt Type:** VERIFICATION  
**Stage / Component:** Abstraction / System Architecture

**Problem / Context:** The Block Diagram includes MQTT Broker, Node-RED, Data Logging, and Web Dashboard, while the final firmware implements local functionality.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL PROMPT ABOUT MQTT / NODE-RED / BLYNK PROJECT SCOPE]

**AI Response (Summary):** AI-assisted architecture discussions included remote monitoring and communication technologies as possible parts of an expanded IoT system.

**Human Delta & Reflection**

- **Critical Thinking:** The architecture cannot be used by itself to claim that cloud communication has been implemented.
    
- **Contextualization:** The final ESP32 program has no operational WiFi, MQTT, Node-RED, or Blynk integration.
    
- **Creative Synthesis:** The team distinguished the local prototype from its proposed cloud/application layer.
    
- **Decision Ownership:** The Final Report must describe local warnings as implemented features and remote monitoring as Future Work.
    

**Evidence:** Block Diagram, firmware source code, project scope documentation.

**Verification Status:** Confirmed architectural discrepancy.

---

# PART II. ALGORITHMS AND FIRMWARE

## Entry 004 – Selecting SAFE, WARNING, and DANGER States

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Algorithms

**Problem / Context:** The system needed consistent warning behavior when different sensors were activated.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL PROMPT ABOUT THREE-STATE DETECTION LOGIC]

**AI Response (Summary):** ChatGPT supported the exploration and explanation of a prioritized rule-based system with distinct warning states.

**Human Delta & Reflection**

- **Critical Thinking:** An OR-based danger condition responds quickly to a single trigger but can also respond to a false sensor activation.
    
- **Contextualization:** G2 uses 40°C for WARNING and 43°C for DANGER, with flame and MQ-2 detection independently activating DANGER.
    
- **Creative Synthesis:** The final logic gives DANGER the highest priority, followed by WARNING and SAFE.
    
- **Decision Ownership:** The team retained simple rule-based classification because it requires no training dataset and can be directly verified through hardware tests.
    

**Evidence:** Firmware decision logic; TC01–TC05 reported PASS.

**Verification Status:** Implemented and functionally tested.

---

## Entry 005 – Temperature Measurement Through the ESP32 ADC

**Prompt Type:** PROBLEM-SOLVING  
**Stage / Component:** Algorithms / Sensor Processing

**Problem / Context:** The LM35 outputs analog voltage, while the system needs temperature in degrees Celsius.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL ADC / LM35 PROMPT]

**AI Response (Summary):** ChatGPT explained ADC measurements, the LM35 nominal voltage-to-temperature relationship, and the influence of electrical noise on sensor readings.

**Human Delta & Reflection**

- **Critical Thinking:** Averaging ADC readings can reduce random fluctuations but does not prove that the temperature measurement is calibrated.
    
- **Contextualization:** The firmware reads GPIO34 with `analogReadMilliVolts()` and averages ten measurements.
    
- **Creative Synthesis:** The implementation converts averaged millivolts to Celsius and uses the result for warning-state classification.
    
- **Decision Ownership:** The team used the existing temperature-processing method while avoiding unsupported quantitative accuracy claims.
    

**Evidence:** `readTemperature()` in firmware, Espressif ADC reference, TC02–TC03.

**Verification Status:** Firmware behavior supported; independent accuracy calibration not documented.

---

## Entry 006 – Automatic Servo Door Control

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Algorithms / Actuator Control

**Problem / Context:** The model door should open automatically when danger is detected while allowing manual operation under non-dangerous conditions.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL SERVO AND BUTTON CONTROL PROMPT]

**AI Response (Summary):** ChatGPT discussed priority rules between automatic actuator control and manual button input.

**Human Delta & Reflection**

- **Critical Thinking:** A manual command must not override the automatic danger response in the implemented design.
    
- **Contextualization:** The SG90 servo is configured for nominal closed and open positions of 0° and 90°.
    
- **Creative Synthesis:** The team implemented forced opening during DANGER and manual toggling when DANGER is inactive.
    
- **Decision Ownership:** Automatic opening was given priority over manual control.
    

**Evidence:** Firmware, TC06–TC08 reported PASS.

**Verification Status:** Implemented and functionally tested.

---

## Entry 007 – Button Debouncing and Manual Door Operation

**Prompt Type:** PROBLEM-SOLVING  
**Stage / Component:** Algorithms

**Problem / Context:** A mechanical button can generate unstable transitions, potentially causing unintended repeated servo actions.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL BUTTON / DEBOUNCE PROMPT]

**AI Response (Summary):** The available technical discussion addressed button-controlled servo operation. A specific original AI response concerning debounce timing has not yet been recovered.

**Human Delta & Reflection**

- **Critical Thinking:** A button event must be distinguished from contact bouncing and repeated program-loop execution.
    
- **Contextualization:** The final firmware uses GPIO33 with `INPUT_PULLUP` and a 50 ms debounce interval.
    
- **Creative Synthesis:** Manual door toggling is conditional on valid button input and the absence of DANGER.
    
- **Decision Ownership:** The firmware implementation is the authoritative source for the debounce behavior.
    

**Evidence:** Firmware button-handling function, TC08.

**Verification Status:** Implementation confirmed; AI involvement and original prompt need verification before retaining this entry.

---

## Entry 008 – Warning Outputs and System Feedback

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Algorithms / Hardware Outputs

**Problem / Context:** The system required distinguishable visual and audible responses for three detection states.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL WARNING OUTPUT DESIGN PROMPT]

**AI Response (Summary):** The project discussions explored LED, buzzer, and LCD indicators for communicating system status.

**Human Delta & Reflection**

- **Critical Thinking:** Using multiple output devices improves observability but does not establish the accuracy of fire detection.
    
- **Contextualization:** The prototype uses three LEDs, one buzzer, an LCD1602, and a servo.
    
- **Creative Synthesis:** SAFE uses a green LED, WARNING uses a yellow LED and intermittent buzzer, and DANGER uses a red LED and continuous buzzer.
    
- **Decision Ownership:** The team selected output behavior that directly represents the three programmed states.
    

**Evidence:** Final firmware, flowchart, functional tests.

**Verification Status:** Implemented; original AI prompt pending.

---

# PART III. VERIFICATION AND AI ERROR DETECTION

## Entry 009 – Verifying GPIO Assignments Against Final Firmware

**Prompt Type:** VERIFICATION  
**Stage / Component:** Pattern Recognition / Hardware Verification

**Problem / Context:** A generated Circuit Schematic did not fully match the final source code.

**Prompt to AI (Verbatim):**

"render chỉnh lại giúp tôi follow theo src code là chuẩn nhất nhé"

**AI Response (Summary):** ChatGPT generated a revised circuit image intended to update GPIO assignments according to the final firmware.

**Human Delta & Reflection**

- **Critical Thinking:** The initial diagram showed Green/Yellow/Red LED pins as GPIO23/25/26, while the final source code used GPIO25/26/27. The revised image also requires further electrical validation because automated image editing does not guarantee a correct schematic.
    
- **Contextualization:** The source code, rather than an AI-generated drawing, is the authoritative reference for firmware pin assignments.
    
- **Creative Synthesis:** The required GPIO mapping was extracted from the code and compared with the labels in the schematic.
    
- **Decision Ownership:** The team must validate all wiring and component connections before accepting the diagram as an accurate electrical representation.
    

**AI Error Category:** Context mismatch / diagram-generation error.

**Evidence:** Original circuit image, revised image, final firmware GPIO definitions.

**Verification Status:** Incorrect GPIO labels identified; full electrical correction still pending.

---

## Entry 010 – Checking Consistency Between Project Documents and Firmware

**Prompt Type:** VERIFICATION  
**Stage / Component:** Pattern Recognition / Research and Documentation

**Problem / Context:** Different project documents reflected different firmware revisions and proposed designs.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL KNOWLEDGE-BASE / SOURCE VERIFICATION PROMPT]

**AI Response (Summary):** Earlier documentation and planning discussions included changing hardware mappings, alert thresholds, and communication features.

**Human Delta & Reflection**

- **Critical Thinking:** A project plan is not sufficient evidence that a feature exists in the final firmware.
    
- **Contextualization:** The final firmware uses temperature thresholds of 40°C and 43°C, one active buzzer, and LED GPIO25/26/27.
    
- **Creative Synthesis:** The team established the final source code as the authoritative reference when preparing system descriptions.
    
- **Decision Ownership:** Outdated planning information must not override the actual implementation.
    

**Evidence:** Project knowledge files, firmware, report preparation notes.

**Verification Status:** Source/document discrepancies identified. The exact AI mistake and original prompt need further confirmation.

---

## Entry 011 – Distinguishing Functional Test Success from Detection Accuracy

**Prompt Type:** VERIFICATION  
**Stage / Component:** Algorithms / Experimental Evaluation

**Problem / Context:** The team reported that all eight functional tests passed. The report must represent this result without overstating scientific performance.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL PROMPT ABOUT TEST RESULTS AND REPORT READINESS]

**AI Response (Summary):** ChatGPT explained that passing predefined functional test cases is different from measuring detection accuracy, false positive rate, or false negative rate.

**Human Delta & Reflection**

- **Critical Thinking:** Eight passing functional test scenarios cannot demonstrate 100% detection accuracy across unknown real-world fire and non-fire conditions.
    
- **Contextualization:** G2 reported successful behavior for TC01–TC08 but did not provide a labeled dataset or confusion matrix.
    
- **Creative Synthesis:** The team organized its evaluation as a functional test matrix with expected and observed behavior.
    
- **Decision Ownership:** The report will state that all eight selected functional tests passed, without presenting unsupported detection accuracy or response-time metrics.
    

**Evidence:** TC01–TC08 summary, firmware behavior, test descriptions.

**Verification Status:** Functional outcomes reported; quantitative detection accuracy not measured.

---

# PART IV. RESEARCH AND LITERATURE VALIDATION

## Entry 012 – Selecting Relevant Scientific References

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Research / Abstraction

**Problem / Context:** The report needed research sources related to ESP32 fire detection, multisensor classification, false alarms, and remote monitoring.

**Prompt to AI (Verbatim):**

"cho tôi thêm 3 link bài bsao cáo có liên qua đến nữa đi"

**AI Response (Summary):** ChatGPT suggested additional research on gas sensor arrays, recurrent neural networks for fire detection, and fuzzy-logic-based IoT warning systems.

**Human Delta & Reflection**

- **Critical Thinking:** An AI-suggested title, DOI, or research finding should be checked against the publication source before citation.
    
- **Contextualization:** The group needed sources that supported the actual prototype and its possible future improvements.
    
- **Creative Synthesis:** The team collected and summarized seven research papers and one technical reference in `IOT-Article.md`.
    
- **Decision Ownership:** Relevant sources were selected for the report, while advanced algorithms not implemented by G2 were reserved for Related Work and Future Work.
    

**Evidence:** `IOT-Article.md`, publisher pages, DOI links, source summaries.

**Verification Status:** Research compilation completed; final BibTeX entries should be checked before submission.

---

## Entry 013 – Comparing Rule-Based Detection with Advanced Classification

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Abstraction / Research

**Problem / Context:** Scientific papers discussed ANN, Decision Tree, Fuzzy Logic, and temporal models, whereas G2 uses simpler programmed conditions.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL RESEARCH-COMPARISON PROMPT]

**AI Response (Summary):** ChatGPT summarized alternative classification approaches and their relationships to multisensor fire detection.

**Human Delta & Reflection**

- **Critical Thinking:** Research models reporting high accuracy on their own datasets cannot be assumed to outperform G2 under untested conditions.
    
- **Contextualization:** The G2 prototype does not have a machine-learning dataset, training pipeline, or model inference component.
    
- **Creative Synthesis:** The report compares the methods conceptually while preserving the implemented rule-based approach.
    
- **Decision Ownership:** G2 retained threshold-based classification for the current prototype and considered advanced sensor fusion as Future Work.
    

**Evidence:** Final firmware and `IOT-Article.md`.

**Verification Status:** Technical comparison supported; original AI prompt pending.

---

## Entry 014 – Evaluating Remote Configuration Through Blynk

**Prompt Type:** DECISION-MAKING  
**Stage / Component:** Abstraction / Future Work

**Problem / Context:** Smoke from cooking or incense may activate the MQ-2 detection output, motivating an exploration of context-aware alert settings.

**Prompt to AI (Verbatim):** [INSERT ORIGINAL PROMPT ABOUT CONFIGURABLE ALERTS / BLYNK]

**AI Response (Summary):** ChatGPT discussed Blynk-based monitoring and configurable warning policies, including limitations of digital-output sensor modules.

**Human Delta & Reflection**

- **Critical Thinking:** Changing an ESP32 software variable does not directly change the hardware comparator threshold of an MQ-2 module using its digital output.
    
- **Contextualization:** G2 currently reads MQ-2 and Flame Sensor through digital inputs, and Blynk is not included in the final firmware.
    
- **Creative Synthesis:** Context-aware configuration was retained as a research direction rather than a completed feature.
    
- **Decision Ownership:** Remote configuration may be investigated later, but critical fire warnings should not be disabled solely because a user expects smoke.
    

**Evidence:** Firmware sensor-reading logic, Blynk-related research, project Future Work notes.

**Verification Status:** Future-work design discussion; no remote configuration implemented.

---

## Entry 015 – Reviewing Technical Diagrams Before Final Reporting

**Prompt Type:** VERIFICATION  
**Stage / Component:** Pattern Recognition / System Verification

**Problem / Context:** The team needed to determine whether the diagrams accurately represented the current system.

**Prompt to AI (Verbatim):**

"render chỉnh lại giúp tôi follow theo src code là chuẩn nhất nhé"

**AI Response (Summary):** ChatGPT revised the circuit image to reflect updated LED pin assignments.

**Human Delta & Reflection**

- **Critical Thinking:** The generated diagram contained labels and connection paths that still required manual checking. A visually plausible diagram is not proof of electrically valid connections.
    
- **Contextualization:** ESP32 GPIOs use 3.3 V logic, while some modules are powered at 5 V.
    
- **Creative Synthesis:** The team identified the need to separate code-level GPIO verification from electrical-level verification, including power supply, logic voltage, grounding, and current-limiting components.
    
- **Decision Ownership:** A circuit image will only be described as validated after checking its connections against the actual prototype and component requirements.
    

**Evidence:** Circuit Schematic versions, firmware pin map, hardware verification checklist.

**Verification Status:** Review in progress. This entry overlaps Entry 009 and should be replaced with a distinct original core prompt if one is available.

---

# PART V. HALLUCINATION AND VERIFICATION REGISTER

The following register distinguishes documented AI output problems from issues that still need to be traced to an original conversation.

|Case|Error or risk|Evidence status|Corrective action|
|---|---|---|---|
|H-01|AI-generated schematic initially showed LED GPIO assignments inconsistent with final firmware|Confirmed|Compare diagram labels against source code|
|H-02|Older architecture descriptions included planned cloud components not present in final firmware|Document discrepancy confirmed; AI hallucination attribution not yet established|Separate implemented and proposed architecture|
|H-03|Older project descriptions contained different temperature thresholds and component configurations|Version discrepancy confirmed; AI hallucination attribution not yet established|Use final firmware as source of truth|

**Important:** H-02 and H-03 must not be counted as confirmed AI hallucinations until the original AI responses and their errors have been identified. A mismatch between document versions is not automatically an AI hallucination.

---

# PART VI. EVIDENCE INDEX

|Evidence ID|Description|
|---|---|
|E01|Final ESP32 firmware, `FireDetectionSingleFinal.ino`|
|E02|Final Flowchart|
|E03|Circuit Schematic – original and revised versions|
|E04|Block Diagram|
|E05|Functional Test Summary, TC01–TC08|
|E06|Literature compilation, `IOT-Article.md`|
|E07|Original ChatGPT conversation excerpts|
|E08|Hardware photographs and Serial Monitor records (to be added)|
|E09|Official course and AI Audit Log guidelines|

---

# PART VII. FINAL REFLECTION

Throughout the IOT102 project, generative AI was used to support technical research, system design exploration, source-code understanding, and documentation.

The most important lesson was that AI-generated explanations and diagrams must be verified against the implemented system. In particular, differences between firmware revisions, inaccurate circuit labels, and proposed cloud features demonstrated why generated information should not be accepted solely on the basis of its presentation.

The team retained responsibility for selecting the project scope, implementing and testing the prototype, and deciding which results could be supported by actual evidence.

The final report and audit documentation distinguish completed implementation, reported functional tests, technical limitations, and proposed future enhancements.

**Prepared by:** Group G2 – SE2027  
**Course:** IOT102 – Fall 2026

**Document status:** Draft for evidence verification, not yet ready for submission.