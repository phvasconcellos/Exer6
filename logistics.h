#ifndef LOGISTICS_H
#define LOGISTICS_H

#define FLAG_FRAGILE      (1 << 0)
#define FLAG_HAZARDOUS    (1 << 1)
#define FLAG_PERISHABLE   (1 << 2)
#define FLAG_URGENT       (1 << 3)
#define FLAG_CUSTOMS_CLR  (1 << 4)
#define FLAG_DELIVERED    (1 << 5)

typedef struct {
    char container_id[16];
    unsigned char flags;
} Cargo;

void set_cargo_attr(Cargo *c, unsigned char flags);
void clear_cargo_attr(Cargo *c, unsigned char flags);
void toggle_cargo_attr(Cargo *c, unsigned char flags);
int check_cargo_condition(Cargo *c, unsigned char flag);
void print_cargo_report(Cargo *c);

#endif