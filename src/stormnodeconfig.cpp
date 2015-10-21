
#include "net.h"
#include "stormnodeconfig.h"
#include "util.h"

CStormnodeConfig stormnodeConfig;

void CStormnodeConfig::add(std::string alias, std::string ip, std::string privKey, std::string txHash, std::string outputIndex) {
    CStormnodeEntry cme(alias, ip, privKey, txHash, outputIndex);
    entries.push_back(cme);
}

bool CStormnodeConfig::read(std::string& strErr) {
    boost::filesystem::ifstream streamConfig(GetStormnodeConfigFile());
    if (!streamConfig.good()) {
        return true; // No stormnode.conf file is OK
    }

    for(std::string line; std::getline(streamConfig, line); )
    {
        if(line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        std::string alias, ip, privKey, txHash, outputIndex;
        if (!(iss >> alias >> ip >> privKey >> txHash >> outputIndex)) {
            strErr = "Could not parse stormnode.conf line: " + line;
            streamConfig.close();
            return false;
        }

/*        if(CService(ip).GetPort() != 31000 && CService(ip).GetPort() != 31000)  {
            strErr = "Invalid port (must be 31000 for mainnet or 31000 for testnet) detected in stormnode.conf: " + line;
            streamConfig.close();
            return false;
        }*/

        add(alias, ip, privKey, txHash, outputIndex);
    }

    streamConfig.close();
    return true;
}
