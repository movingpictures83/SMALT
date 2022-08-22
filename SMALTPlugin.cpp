#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SMALTPlugin.h"

void SMALTPlugin::input(std::string file) {
	readParameterFile(file);
}

void SMALTPlugin::run() {

}

void SMALTPlugin::output(std::string file) {
	myCommand += "smalt map";
	addOptionalParameterNoFlag("genomefile");
	addOptionalParameterNoFlag("sequences");
        addOptionalParameter("-a", "explicit");
        addOptionalParameter("-c", "numbase");
        addOptionalParameter("-d", "threshsw");
        addOptionalParameter("-f", "outputformat");
        addOptionalParameter("-F", "inputformat");
        addOptionalParameter("-g", "sizedist");
        addOptionalParameter("-i", "maxinsert");
        addOptionalParameter("-j", "mininsert");
        addOptionalParameter("-l", "readlib");
        addOptionalParameter("-m", "alignthresh");
        addOptionalParameter("-n", "numthreads");
        addOptionalParameter("-o", "writealign");
        addOptionalParameter("-O", "preserveorder");
        addOptionalParameter("-p", "reportsplit");
        addOptionalParameter("-q", "qualitythreshold");
        addOptionalParameter("-r", "random");
        addOptionalParameter("-S", "setalign");
        addOptionalParameter("-w", "complexweighted");
	addOptionalParameter("-x", "exhaustive");
	addOptionalParameter("-y", "identity");
   myCommand += " >& "+file;
 std::cout << myCommand << std::endl;

 system(myCommand.c_str());
}

PluginProxy<SMALTPlugin> SMALTPluginProxy = PluginProxy<SMALTPlugin>("SMALT", PluginManager::getInstance());
