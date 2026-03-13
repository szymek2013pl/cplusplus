#include <iostream>
#include <vector>
#include <string>

struct SystemLogs {

    std::vector<std::string> raw_logs;
    std::vector<std::string*> error_index;

};

void append_log(SystemLogs* logs, const std::string& log_line) {

    logs->raw_logs.push_back(log_line);

    if (log_line.find("[CRITICAL]") == 0) {

        std::string* adres = &(logs->raw_logs.back());
        
        logs->error_index.push_back(adres);

    }

}

void mark_errors_resolved(SystemLogs* logs) {

    for (int i = 0; i < logs->error_index.size(); i++) {

        *(logs->error_index[i]) += " ROZWIAZANE"; 

    }

}

void print_all_logs(const SystemLogs* logs) {

    for (int i = 0; i < logs->raw_logs.size(); i++) {

        std::cout << logs->raw_logs[i] << std::endl;

    }

}

int main() {

SystemLogs logs;
logs.raw_logs.reserve(100);

append_log(&logs, "linia1");
append_log(&logs, "[CRITICAL] linia2 ");
append_log(&logs, "linia3");

mark_errors_resolved(&logs);

print_all_logs(&logs);
}
