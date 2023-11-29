#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <unordered_map>

class Page {
public:
    int page_num;
    bool referenced;

    Page(int num) : page_num(num), referenced(false) {}
};

class EnhancedClock {
private:
    std::list<Page> page_list;
    std::unordered_map<int, std::list<Page>::iterator> page_table;
    int num_blocks;
    int page_faults; // Track page faults

public:
    EnhancedClock(int blocks) : num_blocks(blocks), page_faults(0) {}

    bool isInMemory(int x) {
        return page_table.find(x) != page_table.end();
    }

    void referencePage(int x) {
        if (isInMemory(x)) {
            auto it = page_table[x];
            it->referenced = true;
        }
        else {
            ++page_faults; // Increment page fault count
            Page new_page(x);
            if (page_list.size() < num_blocks) {
                page_list.push_back(new_page);
                auto it = std::prev(page_list.end());
                page_table[x] = it;
            }
            else {
                bool page_replaced = false;
                while (!page_replaced) {
                    for (auto it = page_list.begin(); it != page_list.end(); ++it) {
                        if (!it->referenced) {
                            page_table.erase(it->page_num);
                            *it = new_page;
                            page_table[x] = it;
                            page_replaced = true;
                            break;
                        }
                        it->referenced = false; // Give a second chance
                    }
                }
            }
        }
    }

    double getPageFaultRate(int total_references) {
        return static_cast<double>(page_faults) / total_references;
    }
};

int main() {
    EnhancedClock clock_algo(4); // 4 blocks for example

    clock_algo.referencePage(1);
    clock_algo.referencePage(2);
    clock_algo.referencePage(3);
    clock_algo.referencePage(1);
    clock_algo.referencePage(4);
    clock_algo.referencePage(2);

    int total_references = 6; // Total references made in the simulation
    double page_fault_rate = clock_algo.getPageFaultRate(total_references);
    std::cout << "缺页率为: " << page_fault_rate << std::endl;

    return 0;
}
