//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#ifndef REGISTERCONTROLLER_H
#define REGISTERCONTROLLER_H
#include "../Model/Register.h"


class RegisterController {
public:
    /**
     * Assenza di errori
     */
    static constexpr int ERROR_NONE = 0;

    /**
     * Descrizione non valida
     */
    static constexpr int INVALID_DESCRIPTION = 1;

    /**
     * Range di date non valido
     */
    static constexpr int INVALID_DATE_RANGE = 2;

    /**
     * Attività duplicata
     */
    static constexpr int DUPLICATED_ACTIVITY = 3;

    /**
     * Errore generico
     */
    static constexpr int UNEXPECTED_ERROR = 4;


    /**
     * Costruttore di classe
     * @param reg Puntatore a Registro
     */
    explicit RegisterController(Register *reg) : reg(reg) {}

    /**
     * Aggiuntà di un'attività nel registro validando i dati della view.
     * @param description Descrizione attività
     * @param start Data e ora di inizio
     * @param end Data e ora di fine
     * @return Codice di errore
     */
    int addActivity(const QString &description, const QDateTime &start, const QDateTime &end) const;

    /**
     * Rimozione di un'attività nel registro validando i dati della view
    * @param description Descrizione attività
     * @param start Data e ora di inizio
     * @return Codice di errore
     */
    int removeActivity(const QString &description, const QDateTime &start) const;

    /**
     * Rimozione di tutte le attività del registro
     */
    void clearAllActivities() const;

    /**
     * Filtraggio attività del registro in base a una data
     * @param date Data di inizio
     */
    void filterAllActivities(const QDate &date) const;

    /**
     * Ripristino del filtro precedente
     */
    void resetAllActivities() const;

private:
    Register *reg;
};


#endif //REGISTERCONTROLLER_H
