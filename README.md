# via_hardware_executables
Projects to build the executable files for the Via modules.

## Buiding
You can work within one of two build environments: the [Via Development Environment Vagrant box](https://github.com/starlingcode/via-dev-environment) or [System Workbench for STM32](https://www.openstm32.org/System+Workbench+for+STM32). Both options offer support for Mac, Windows, or Linux machines.

### Setting up Vagrant Box
See the readme for the [Via Development Environment Vagrant box](https://github.com/starlingcode/via-dev-environment) for setup and build instructions.

### Setting up a System Workbench for STM32
First, [install the System Workbench application](https://www.openstm32.org/System+Workbench+for+STM32). You will need to register an account with OpenSTM32 to access the download and installation instructions.

Once you have installed the application, create a new empty workspace.

From the Project Explorer, right click and select "Import...".

In the wizard, select "Git->Projects from Git" and click "Next >".

Select "Clone URI" and click "Next >".

In the URI flield, copy and paste the clone link for this repo. That should populate all necessary fields, and you can click "Next >".

Select the branches you want to clone, it works fine to start with "master". Click "Next >".

Choose a destination directory on your machine for the cloned respository. Select master as the Initial Branch, and be sure to check "Clone submodules". Then, click "Next >".

The repository will be cloned. Once this is complete, make sure the radio button selector is set to "Import existing Eclipse projects"

A project for the drivers and each module should be detected. You can click Finish and start building!

### Building and flashing in System Workbench
Lets assume you just set up the Eclipse environment. You will want to build the Release and Debug configurations for hardware_drivers first. The builds a static library used by the individual module executable projects. 

Then, you can build the module of choice by building the Release and Debug configurations of that project. 

From there, you can hit the play button in the top menu to flash over STLink. The connection used on the Via modules is SWD, and pin 1 on the Via module is oriented towards the top of the module.

You will probably never have to edit the individual module project source (unless you want to mess with the hardware initialization/interrupt priority, etc.). Rather, you will edit the Via submodule in the hardware_drivers project. That contains the fun part of the code that animates the modules at run time.
