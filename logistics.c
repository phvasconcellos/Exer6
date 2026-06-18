#include <stdio.h>
#include "logistics.h"

void set_cargo_attr(Cargo *c, unsigned char flags) {
    c->flags |= flags;
}

void clear_cargo_attr(Cargo *c, unsigned char flags) {
    c->flags &= ~flags;
}

void toggle_cargo_attr(Cargo *c, unsigned char flags) {
    c->flags ^= flags;
}

int check_cargo_condition(Cargo *c, unsigned char flag) {
    return (c->flags & flag) == flag;
}

void print_cargo_report(Cargo *c) {
    printf("Container: %s | Status Hex: 0x%02X\n", c->container_id, c->flags);
    printf("  [ ] Fragil:             %s\n", check_cargo_condition(c, FLAG_FRAGILE) ? "SIM" : "NAO");
    printf("  [ ] Carga Perigosa:     %s\n", check_cargo_condition(c, FLAG_HAZARDOUS) ? "SIM" : "NAO");
    printf("  [ ] Perecivel/Refrig.:  %s\n", check_cargo_condition(c, FLAG_PERISHABLE) ? "SIM" : "NAO");
    printf("  [ ] Urgente:            %s\n", check_cargo_condition(c, FLAG_URGENT) ? "SIM" : "NAO");
    printf("  [ ] Liberado Alfandega: %s\n", check_cargo_condition(c, FLAG_CUSTOMS_CLR) ? "SIM" : "NAO");
    printf("  [ ] Entregue:           %s\n", check_cargo_condition(c, FLAG_DELIVERED) ? "SIM" : "NAO");
    printf("--------------------------------------------\n");
}