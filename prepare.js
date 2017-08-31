#!/usr/local/bin/node
/**
*	@file configure.js
*	@brief A script for automating various task pertaining to preparing a release.
*	@author Anadian
*	@copyright MIT License
*/
const FileSystem = require('fs');
const CommandLineArgs = require('command-line-args');
const OptionDefinitions = [
	{name: 'version', alias: 'V', type: String},
	{name: 'help', alias: 'h', type: Boolean},
	{name: 'verbose', alias: 'v', type: Boolean},
	{name: 'noop', alias: 'n', type: Boolean},
	{name: 'installdependencies', alias: 'i', type: Boolean},
	{name: 'setversion', alias: 's'. type: String}
];
const Options = CommandLineArgs(OptionDefinitions);
if(Options.verbose == true) console.log('Options: ', Options);

function SetVersion(major, minor, patch){
	var version_string = major + '.' + minor + '.' + patch;
	var PackageBuffer = FileSystem.readFileSync('./package.json');
	var PackageText = PackageBuffer.toString('utf8');
	PackageText.replace(/"version": "[^"]",/, ('\"version\": \"' + version_string + '\",'));

if(Options.setversion != null){
	var strings = Options.setversion.split(/\./);
	if(Options.verbose) console.log('strings: ', strings);
	var version = {
		major: strings[0],
		minor: strings[1],
		patch: strings[2]
	};
		UpdateSource(version);
	UpdateMakefile(version);
