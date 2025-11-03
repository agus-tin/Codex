#include "ArchivoAdmin.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

ArchivoAdmin::ArchivoAdmin(const char* n) {
    strcpy(_nombre, n);
}

void ArchivoAdmin::grabarRegistro(Admin obj) {
    FILE* p;
    p = fopen(_nombre, "ab");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        return;
    }
    fwrite(&obj, sizeof(Admin), 1, p);
    fclose(p);
}

Admin ArchivoAdmin::leerRegistro(int pos) {
    Admin obj;
    FILE* p;
    p = fopen(_nombre, "rb");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        obj.setadminID(-2);
        return obj;
    }
    fseek(p, pos * sizeof(Admin), 0);
    fread(&obj, sizeof(Admin), 1, p);
    fclose(p);
    return obj;
}

int ArchivoAdmin::contarRegistros() {
    FILE* p;
    p = fopen(_nombre, "rb");
    if (p == NULL) {
        return -1;
    }
    fseek(p, 0, 2);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes / sizeof(Admin);
}

int ArchivoAdmin::buscarRegistroUsuario(const char* usuario) {
    Admin obj;
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        if (strcmp(obj.getusuario(), usuario) == 0) {
            return i;
        }
    }
    return -1;
}

int ArchivoAdmin::ultimoRegistro() {
    FILE* p;
    p = fopen(_nombre, "rb");
    if (p == NULL) {
        return 1;
    }

    Admin obj;
    int maximo = 0;

    while (fread(&obj, sizeof(Admin), 1, p) == 1) {
        if (obj.getadminID() > maximo) {
            maximo = obj.getadminID();
        }
    }
    fclose(p);
    return maximo + 1;
}

void ArchivoAdmin::listarArchivo() {
    int cant = contarRegistros();
    Admin obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        if (obj.getEstado() == true) {
            obj.mostrar();
            cout << endl;
        }
    }
}

void ArchivoAdmin::modificarRegistro(Admin obj, int pos) {
    FILE* p;
    p = fopen(_nombre, "rb+");
    if (p == NULL) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
        return;
    }
    fseek(p, pos * sizeof(Admin), 0);
    fwrite(&obj, sizeof(Admin), 1, p);
    fclose(p);
}

bool ArchivoAdmin::copiaSeguridadRegistro() {
    Admin obj;
    FILE* p;
    FILE* pBack;
    p = fopen(_nombre, "rb");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    pBack = fopen("Admin.bak", "wb");
    if (pBack == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        fclose(p);
        return false;
    }

    while (fread(&obj, sizeof(Admin), 1, p) == 1) {
        if (obj.getEstado() == true) {
            fwrite(&obj, sizeof(Admin), 1, pBack);
        }
    }
    fclose(p);
    fclose(pBack);
    return true;
}

bool ArchivoAdmin::restaurarRegistro() {
    Admin obj;
    FILE* pBack;
    FILE* p;
    pBack = fopen("Admin.bak", "rb");
    if (pBack == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    p = fopen(_nombre, "wb");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        fclose(pBack);
        return false;
    }
    while (fread(&obj, sizeof(Admin), 1, pBack) == 1) {
        fwrite(&obj, sizeof(Admin), 1, p);
    }
    fclose(p);
    fclose(pBack);
    return true;
}
