#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hasSuspiciousExtension(string name) {
    string exts[] = {".exe", ".bat", ".vbs", ".js", ".scr", ".com"};
    for (int i = 0; i < 6; i++) {
        if (name.size() >= exts[i].size()) {
            if (name.substr(name.size() - exts[i].size()) == exts[i]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of sandbox file names: ";
    cin >> n;

    vector<string> files(n);
    cout << "Enter file names:\n";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    cout << "\nScan Report\n";
    for (int i = 0; i < n; i++) {
        if (hasSuspiciousExtension(files[i])) {
            cout << files[i] << " -> suspicious pattern detected\n";
        } else {
            cout << files[i] << " -> normal\n";
        }
    }

    string agentName;
    int copies;
    cout << "\nEnter a demo agent name: ";
    cin >> agentName;
    cout << "Enter number of virtual copies to simulate: ";
    cin >> copies;

    vector<string> sandboxCopies;
    for (int i = 1; i <= copies; i++) {
        sandboxCopies.push_back("copy_" + to_string(i) + "_" + agentName);
    }

    cout << "\nVirtual Replication Log\n";
    for (int i = 0; i < (int)sandboxCopies.size(); i++) {
        cout << sandboxCopies[i] << "\n";
    }

    cout << "\nThis was only an in-memory classroom simulation.\n";

    return 0;
}