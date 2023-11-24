![](Aspose.Words.6bc128f4-9d5a-4807-9a63-898001576434.002.png)![](Aspose.Words.6bc128f4-9d5a-4807-9a63-898001576434.003.png)![](Aspose.Words.6bc128f4-9d5a-4807-9a63-898001576434.004.png)


![](Aspose.Words.6bc128f4-9d5a-4807-9a63-898001576434.005.png)![](Aspose.Words.6bc128f4-9d5a-4807-9a63-898001576434.006.png)
![](Aspose.Words.6bc128f4-9d5a-4807-9a63-898001576434.007.png)

Table of Contents

[1 Introduction and Initial Analysis	2](#_heading=h.gjdgxs)

[1.1 Project Context	2](#_heading=h.30j0zll)

[1.2 Initial Thought Process	2](#_heading=h.1fob9te)

[2 Requirement Analysis and Specification	2](#_heading=h.3znysh7)

[2.1 User Requirements	2](#_heading=h.2et92p0)

[2.2 System Requirements	2](#_heading=h.tyjcwt)

[2.3 Tools and Technologies	2](#_heading=h.3dy6vkm)

[3 Conceptual Design	2](#_heading=h.1t3h5sf)

[3.1 System Architecture	2](#_heading=h.4d34og8)

[3.2 Interface Design	2](#_heading=h.2s8eyo1)

[3.3 Control Algorithm Design	3](#_heading=h.17dp8vu)

[4 Detailed Design and Development	3](#_heading=h.3rdcrjn)

[4.1 Component Design	3](#_heading=h.26in1rg)

[4.2 Coding and Implementation	3](#_heading=h.lnxbz9)

[4.3 Integration	3](#_heading=h.35nkun2)

[4.4 Unique Features	3](#_heading=h.1ksv4uv)

[5 Testing, Evaluation, and Optimization	3](#_heading=h.44sinio)

[5.1 Testing Strategy	3](#_heading=h.2jxsxqh)

[5.2 Performance Evaluation	3](#_heading=h.z337ya)

[5.3 Optimization	3](#_heading=h.3j2qqm3)

[6 Collaboration and Project Management	3](#_heading=h.1y810tw)

[6.1 Teamwork Dynamics	3](#_heading=h.4i7ojhp)

[6.2 Project Management	3](#_heading=h.2xcytpi)

[7 Conclusion and Reflection	3](#_heading=h.1ci93xb)

[7.1 Project Summary	3](#_heading=h.3whwml4)

[7.2 Future Work	3](#_heading=h.2bn6wsx)

[7.3 Personal and Group Reflections	3](#_heading=h.qsh70q)

[8 Appendices	4](#_heading=h.3as4poj)

[8.1 Bill of Materials	4](#_heading=h.1pxezwc)

[8.2 Electrical Wiring and System Layout	4](#_heading=h.49x2ik5)

[8.3 Code Repository	4](#_heading=h.2p2csry)

[8.4 Additional Documentation	4](#_heading=h.147n2zr)

[9 References	4](#_heading=h.3o7alnk)











<a name="_heading=h.gjdgxs"></a>
# 1 INTRODUCTION
## <a name="_heading=h.30j0zll"></a>1.1 Background.
In the industrial era 5.0 sophisticated robots are no longer an amazing thing when we encounter, seeing the many technologies that are developing rapidly we are forced to adapt to technological advances. We often encounter modern technology in the work environment, schools, communities and even home environments, even some of them have also used artificial intelligence.

Robots were originally created to replace human labor when it comes to dangerous areas. Examples are used in various industries such as automotive, manufacturing, agriculture, health, and others. Some types of robots that are often used in industry include robot arms, humanoid robots, mobile robots, cartesian and many others. The development of robotics continues to grow rapidly and has become one of the fields that attract attention around the world. Along with technological advances, in the future robotics is expected to help humans not only in manufacturing and industry but also to meet the needs of the umkm community.

GUI (Graphical user Interface) is a type of interface that uses visual elements such as button icons, windows and menus to allow users to interact with software or operating systems visually. The existence of a GUI can make it easier for users to interact directly with software without having to master complex program text commands. In addition to making it easier for users, by using a GUI users can visualize data, streamline user time to increase productivity, facilitate user interaction with software and many more universal GUI functions.

Cartesian robots are robots that are influential in human life in industry. Moving heavy goods that cannot be done by human labor can be assisted by cartesian robots. Cartesian robots can execute commands to move consistently on the X, Y and Z axis ordinates so that cartesian robots can move freely forward-backward, right-left, and also up and down. Not only for moving goods, cartesian robots are able to help humans to carry out robot functions as automatic welding, material cutting, 3D printing, food industry, lasser cutting, food and health industry and even hazardous environments in the industry.

The development we are doing now uses a cartesian robot, with a GUI (Graphical User Interface) interface we hope to be able to create a control that gives commands to the robot to carry out movements according to the commands sent.
## 1\.2 Problem Formulation
what is a cartesian robot?

What commands will be given to the GUI?

How to find the displacement value of motion in the X-axis and Y-axis in stepper rotation?
## 1\.3 Research Objectives
`	`By creating a GUI program to control the cartesian robot, we hope to:

1\. find a solution to the problem at hand.

2\. find the maximum and minimum coordinate points on the X and Y axes.

3\. put the fulcrum of the robot pen at the desired coordinates.
# <a name="_heading=h.3znysh7"></a>2 Requirements Analysis and Specification
## <a name="_heading=h.2et92p0"></a>2.1 User Requirements

The Graphic User Interface (GUI) system for controlling cartesian robots is designed with the main purpose of providing convenience to users in programming and real-time monitoring of robot movements towards the inputted cartesian coordinate position. The GUI interface is structured so that users can easily input robot movement commands with flexible formats, visualization of robot movements is presented clearly through graphical representations or animations, and robot status information is updated in real-time. In terms of programming, the GUI provides intuitive navigation menus and provides clear error notifications along with troubleshooting suggestions. In addition, there may be a simulation mode to test the program before it is actively implemented. By focusing on these elements, it is hoped that this GUI can provide an efficient and effective user experience, both in programming and monitoring robot tasks.
## 2\.2 System Requirements
Technically, the cartesian robot control GUI was designed using the python programming language and software development technologies that support graphical representation and user interaction. The interface utilizes input from the user, such as the desired cartesian coordinates for the purpose of robot movement. The system includes programming functions that process user input and generate appropriate control commands for the robot. The software is also connected with a monitoring system that continuously updates real-time robot status and position information.

Functionally, the GUI focuses on allowing the user to perform two main functions: programming and monitoring. The programming function involves the design of an interface that allows users to enter robot movement commands with a coordinate format that the system can understand. Visual representations, such as graphics and animations, provide a clear picture of the robot's movements according to user inputs. Monitoring functions allow users to directly see the status and position of the robot as it performs its tasks. Clear error notifications and troubleshooting suggestions enhance the user's responsiveness to situations that may occur during operation. The simulation mode can act as a trial tool before active implementation, ensuring the accuracy and safety of robot movements. Thus, technically and functionally, this GUI integrates input, processing, and output to provide an optimal user experience in controlling and monitoring the cartesian robot..


## <a name="_heading=h.3dy6vkm"></a>2.3 Tools and Technologies
- software
1. QT creator
1. Arduino IDE
- hardware
1. arduino nano
1. cnc shield
1. nema 17
1. motor servo SG90
1. Spacer
1. base dari akrilik
1. kabel upload
1. adaptor DC 12volt
1. bearing
1. frame rangka
1. LM 

## 2\.4 Target specification
*Tabel 1. Tabel caption.*

|**Minggu Ke-**|**Keterangan**|**Tolok Ukur**|**sasaran**|
| :-: | :-: | :-: | :-: |
|**1**|Detail of the feature|Units/Scale/Methodology|Specified Value|
|**2**|...|...|...|
|**3**||||
|**4**||||
|**5**||||
|**6**||||
|**7**||||
|**8**||||

# <a name="_heading=h.1t3h5sf"></a>3 Conceptual Design
## <a name="_heading=h.4d34og8"></a>3.1 System Architecture
Illustrate the high-level architecture of the system, including the GUI and control logic.
## <a name="_heading=h.2s8eyo1"></a>3.2 Interface Design
Sketch the preliminary design of the GUI, focusing on user interaction and experience.
## <a name="_heading=h.17dp8vu"></a>3.3 Control Algorithm Design
Outline the design of control algorithms and data processing workflows.
# <a name="_heading=h.3rdcrjn"></a>4 Detailed Design and Development
## <a name="_heading=h.26in1rg"></a>4.1 Component Design
Delve into the design of individual components, modules, and functionalities.
## <a name="_heading=h.lnxbz9"></a>4.2 Coding and Implementation
Document the coding process, adopted standards, and implementation challenges.
## <a name="_heading=h.35nkun2"></a>4.3 Integration
Discuss the integration of GUI with the control system, and among different system components.
## <a name="_heading=h.1ksv4uv"></a>4.4 Unique Features
Highlight any novel features, optimizations or technologies employed.
# <a name="_heading=h.44sinio"></a>5 Testing, Evaluation, and Optimization
## <a name="_heading=h.2jxsxqh"></a>5.1 Testing Strategy
<a name="_heading=h.z337ya"></a>Describe the testing methodologies, cases, and tools used. Emphasize on how the testing validates the targets specified in Section 2.4.
## 5\.2 Performance Evaluation
<a name="_heading=h.3j2qqm3"></a>Evaluate the system performance against the defined requirements and objectives. Include a comparative analysis with the targets specified in Section 2.4, illustrating how well the system meets or exceeds these targets.
## 5\.3 Optimization
Discuss any optimizations made to enhance system performance and user experience.
# <a name="_heading=h.1y810tw"></a>6 Collaboration and Project Management
## <a name="_heading=h.4i7ojhp"></a>6.1 Teamwork Dynamics
Reflect on the collaborative endeavor, roles, and contributions of team members.
## <a name="_heading=h.2xcytpi"></a>6.2 Project Management
Document the project timeline, milestones, and management practices adopted.
# <a name="_heading=h.1ci93xb"></a>7 Conclusion and Reflection
## <a name="_heading=h.3whwml4"></a>7.1 Project Summary
Summarize the key achievements, learnings, and outcomes.
## <a name="_heading=h.2bn6wsx"></a>7.2 Future Work
Propose further enhancements, applications, and research directions.
## <a name="_heading=h.qsh70q"></a>7.3 Personal and Group Reflections
Reflect on the experience, challenges, and acquired knowledge.
# <a name="_heading=h.3as4poj"></a>8 Appendices
## <a name="_heading=h.1pxezwc"></a>8.1 Bill of Materials
Detail the parts, costs, and sources.
## <a name="_heading=h.49x2ik5"></a>8.2 Electrical Wiring and System Layout
Provide diagrams, schematics, and layout information.
## <a name="_heading=h.2p2csry"></a>8.3 Code Repository
Include links to the code repository, version control, and change logs.
## <a name="_heading=h.147n2zr"></a>8.4 Additional Documentation
Include any other relevant documentation, photos, or supporting materials.
# <a name="_heading=h.3o7alnk"></a>9 References
Cite all references, tools, libraries, and external resources used in the project.
7

