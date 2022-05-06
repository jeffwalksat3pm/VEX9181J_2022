Version Overviews and Changelog
Ver.0.X.X - "Fresh":
1st gen new frameworks and basic functional operations; Alpha / Beta development;

Ver 0.1.0 - “Fresh” Alpha Ver 0
Code for December WestVan Tournament;
Last Edit: Dec 10, 2021 at 15:50 (3:50pm)
Edit by: Jeff Sun
//Features and Fixes//
Overall basic framework done
Improved structure
Beta; Therefore experimental
//Known Issues, Tasks//
Needs fix on some initialization
No opcontrol and no autonomous written
Compiling error due to PROS issue
Missing sensors, pneumatics and port numbers for the lift motors
Ver 0.1.1 - “Fresh” Alpha Ver 1
Code for December WestVan Tournament;
Last Edit: Dec 10, 2021 at 22:31 (10:31pm)
Edit by: Ryu Sado
//Features and Fixes//
Fixed on builder initialization issue
Fixed on previous PROS issue
Added missing sensors, pneumatics and missing port numbers for lift motors
Wrote basic driver code
//Known Issues, Tasks//
Front lift minimum limiter not working? (Rotation sensor not properly utilized?)
No autonomous written
Autonomous functions not tested yet; May contain errors / bugs
Ver 0.1.2 - “Fresh” Alpha Ver 2
Live Code at December WestVan Tournament;
Last Edit: Dec 11, 2021 at 18:30 (6:30pm)
Edit by: Ryu Sado
//Features and Fixes//
Fixed initialization issue on comp mode
Inverted initialization for backlift
Added functionality to manually set backlift angle limit
Other minor error/bug fixes
//Known Issues, Tasks//
Autonomous functions not tested yet; May contain errors/bugs

—--------PROVINCIALS—-------------------------------
Ver 0.1.3 -  "Fresh" Alpha Ver 3
Code for provincials tournament
Last Edit: Feb 27, 2022
Edit by: Jeff Sun

//Features and Fixes//
 - Added rotation sensor functions
 - Added PID controller options
 - Added modechange functions;
//Known Issues, Tasks//
 - Needs new autonomous

Ver 0.1.4 - "Fresh" Alpha Ver 4
Code for provincials tournament
Last Edit: Feb 28, 2022
Edit by: Ryu Sado
//Features and Fixes//
 - Added 2 match auto functions.
 - Removed autonomous code test function in opcontrol.
 - Slight mods on driver controls and conveyer speed.
//Known Issues, Tasks//
 - Need to balance velocities between left and right to compensate jumps when accelerating.
 - Need to use velocities and timed controls on most part since there are collisions and I cannot tell something asynchronously.

Ver 0.1.5 - "Fresh" Alpha Ver 5
Code for provincials tournament
Last Edit: Mar 1, 2022
Edit by: Ryu Sado
//Features and Fixes//
 - Added match autonomous BMajor();
 - Modded AMinor(); for consistency and renamed redAMinor(); since it is modified only for the red A side.
 - Added liftIntake(); in autonomous controller.
//Known Issues, Tasks//
 - Create and tweak blueAMinor();

Ver 0.2.1 - "Fresh" Beta Ver 1
Code for provincials tournament
Last Edit: Mar 2, 2022
Edit by: Ryu Sado / Jeff Sun
//Features and Fixes//
 - BMajor(); completed
 - Fixed driveAndApproach();function.
 - Added driveAndIntake();
 - Enabled rearClinch() button on the driver control.
 - Other minor error/bug fixes
//Known Issues, Tasks//
 - driveAndIntake, driveAndApproach both have bugs - distance sensor values are funny.
