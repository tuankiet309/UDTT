#include <iostream>
#include <vector>
#include <algorithm>

// Struct representing a job
struct Job {
    std::string id;
    int start_time;
    int duration;
};

// Function to display the list of jobs in reverse order recursively
void displayJobsReverse(const std::vector<Job>& jobs, int index) {
    if (index < 0) // Base case: stop when index is out of range
        return;
    
    std::cout << "Job ID: " << jobs[index].id << ", Start Time: " << jobs[index].start_time 
              << ", Duration: " << jobs[index].duration << " minutes" << std::endl;
    
    // Recursively call displayJobsReverse with the previous index
    displayJobsReverse(jobs, index - 1);
}

// Function to generate combinations of jobs (5 jobs) using backtracking
void generateCombinations(const std::vector<Job>& jobs, std::vector<Job>& combination, 
                          std::vector<std::vector<Job>>& result, int index, int count) {
    if (count == 5) { // Base case: if 5 jobs have been selected
        result.push_back(combination); // Add the combination to the result
        return;
    }
    
    // Iterate over remaining jobs
    for (int i = index; i < jobs.size(); ++i) {
        combination.push_back(jobs[i]); // Include the current job in the combination
        generateCombinations(jobs, combination, result, i + 1, count + 1); // Recur with next index and count
        combination.pop_back(); // Backtrack: remove the current job from the combination
    }
}

int main() {
    // Sample list of jobs
    std::vector<Job> jobs = {
        {"J1", 8, 120},
        {"J2", 9, 90},
        {"J3", 10, 60},
        {"J4", 11, 180},
        {"J5", 13, 150},
        {"J6", 14, 100},
        {"J7", 15, 140},
        {"J8", 16, 110},
        {"J9", 17, 170},
        {"J10", 18, 130}
    };

    // Displaying jobs in reverse order recursively
    std::cout << "Jobs in reverse order:" << std::endl;
    displayJobsReverse(jobs, jobs.size() - 1);

    // Generating combinations of 5 jobs
    std::vector<std::vector<Job>> combinations;
    std::vector<Job> combination;
    generateCombinations(jobs, combination, combinations, 0, 0);

    // Displaying combinations
    std::cout << "\nAll combinations of 5 jobs:" << std::endl;
    for (const auto& comb : combinations) {
        std::cout << "Combination:";
        for (const auto& job : comb) {
            std::cout << " " << job.id;
        }
        std::cout << std::endl;
    }

    return 0;
}