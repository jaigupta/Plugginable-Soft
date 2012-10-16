Plugginable-Soft
================

A Plugginable Core Software Framework implemented using Qt

[*] Project Core
-----------------
The Core is the main software to which all the plugins are added. The core can be extended by plugins. 
The Core provides an interface which should be implemenetd by all plugins and access to the GUI components of the core is provided by the interface.
The entryPoint method of the Interface is responsible to provide the Plugins with objects of the Core's GUI components wrapped up through simple functions

[*] Project commonLibs
----------------------
Project for the common Library shared by both the plugin as well as the core project.

[*] Project MyPlugin
--------------------
A sample plugin demonstrating how to implement the interface and demontrating way to add menu items to the core software.
This Plugin adds an alarm clock to the given software.
