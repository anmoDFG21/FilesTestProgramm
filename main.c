#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define k_MAX_USERS 100

int g_i_user_count = 0;
char* g_username;

static char* s_pc_welcome_message = "Welcome!";

typedef struct {
    int m_i_id;
    char* m_pc_name;
    float m_salary;
    bool is_active;
} User;

void print_user_info(User st_user) {
    printf("ID: %d\n", st_user.m_i_id);
    printf("Name: %s\n", st_user.m_pc_name);
}

void add_user(char* pc_name) {
    if (g_i_user_count >= k_MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    User newUser;
    newUser.m_i_id = g_i_user_count;
    newUser.m_pc_name = pc_name;
    newUser.m_salary = 50000.0f;
    newUser.is_active = true;

    print_user_info(newUser);
    g_i_user_count++;
}

int main() {
    printf("%s\n", s_pc_welcome_message);

    char name[50];
    strcpy(name, "Alice");

    add_user(name);
    return 0;
}

