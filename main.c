#include <stdio.h>
#include "logistics.h"

int main() {
    Cargo c1 = {"CONT-BR9921", 0};

    printf("=== SISTEMA DE RASTREAMENTO LOGISTICO ===\n\n");

    printf("[ETAPA 1] Recebimento no Porto\n");
    set_cargo_attr(&c1, FLAG_HAZARDOUS | FLAG_URGENT);
    print_cargo_report(&c1);

    printf("[ETAPA 2] Inspecao da Alfandega\n");
    set_cargo_attr(&c1, FLAG_CUSTOMS_CLR);
    print_cargo_report(&c1);

    printf("[ETAPA 3] Atualizacao de Rota\n");
    clear_cargo_attr(&c1, FLAG_URGENT);
    toggle_cargo_attr(&c1, FLAG_FRAGILE);
    print_cargo_report(&c1);

    printf("[DECISAO DO SISTEMA DE EMBARQUE]\n");
    if (check_cargo_condition(&c1, FLAG_HAZARDOUS) && check_cargo_condition(&c1, FLAG_CUSTOMS_CLR)) {
        printf("=> STATUS VERDE: Carga perigosa documentada e liberada para o navio.\n");
    } else {
        printf("=> STATUS VERMELHO: Reter carga por falha de documentacao!\n");
    }

    return 0;
}
