#ifndef PROGRAMAACADEMICO_H
#define PROGRAMAACADEMICO_H

#include <string>
#include <vector>
#include "Consolidado.h"
#include "Constantes.h"

using namespace std;

class ProgramaAcademico {
private:
    int codigoDeLaInstitucion;
    int iesPadre;
    string institucionDeEducacionSuperiorIes;
    string principalOSeccional;
    int idSectorIes;
    string sectorIes;
    int idCaracter;
    string caracterIes;
    int codigoDelDepartamentoIes;
    string departamentoDeDomicilioDeLaIes;
    int codigoDelMunicipioIes;
    string municipioDeDomicilioDeLaIes;
    int codigoSniesDelPrograma;
    string programaAcademico;
    int idNivelAcademico;
    string nivelAcademico;
    int idNivelDeFormacion;
    string nivelDeFormacion;
    int idMetodologia;
    string metodologia;
    int idArea;
    string areaDeConocimiento;
    int idNucleo;
    string nucleoBasicoDelConocimientoNbc;
    int idCineCampoAmplio;
    string descCineCampoAmplio;
    int idCineCampoEspecifico;
    string descCineCampoEspecifico;
    int idCineCodigoDetallado;
    string descCineCodigoDetallado;
    int codigoDelDepartamentoPrograma;
    string departamentoDeOfertaDelPrograma;
    int codigoDelMunicipioPrograma;
    string municipioDeOfertaDelPrograma;
    vector<Consolidado *> consolidados;

public:
    ProgramaAcademico();
    
    void setCodigoDeLaInstitucion(int nuevoCodigoDeLaInstitucion);
    int getCodigoDeLaInstitucion();
    
    void setIesPadre(int nuevoIesPadre);
    int getIesPadre();
    
    void setInstitucionDeEducacionSuperiorIes(string &nuevoInstitucionDeEducacionSuperiorIes);
    string getInstitucionDeEducacionSuperiorIes();
    
    void setPrincipalOSeccional(string &nuevoPrincipalOSeccional);
    string getPrincipalOSeccional();
    
    void setIdSectorIes(int nuevoIdSectorIes);
    int getIdSectorIes();
    
    void setSectorIes(string &nuevoSectorIes);
    string getSectorIes();
    
    void setIdCaracter(int nuevoIdCaracter);
    int getIdCaracter();
    
    void setCaracterIes(string &nuevoCaracterIes);
    string getCaracterIes();
    
    void setCodigoDelDepartamentoIes(int nuevoCodigoDelDepartamentoIes);
    int getCodigoDelDepartamentoIes();
    
    void setDepartamentoDeDomicilioDeLaIes(string &nuevoDepartamentoDeDomicilioDeLaIes);
    string getDepartamentoDeDomicilioDeLaIes();
    
    void setCodigoDelMunicipioIes(int nuevoCodigoDelMunicipioIes);
    int getCodigoDelMunicipioIes();
    
    void setMunicipioDeDomicilioDeLaIes(string &nuevoMunicipioDeDomicilioDeLaIes);
    string getMunicipioDeDomicilioDeLaIes();
    
    void setCodigoSniesDelPrograma(int nuevoCodigoSniesDelPrograma);
    int getCodigoSniesDelPrograma();
    
    void setProgramaAcademico(string &nuevoProgramaAcademico);
    string getProgramaAcademico();
    
    void setIdNivelAcademico(int nuevoIdNivelAcademico);
    int getIdNivelAcademico();
    
    void setNivelAcademico(string &nuevoNivelAcademico);
    string getNivelAcademico();
    
    void setIdNivelDeFormacion(int nuevoIdNivelDeFormacion);
    int getIdNivelDeFormacion();
    
    void setNivelDeFormacion(string &nuevoNivelDeFormacion);
    string getNivelDeFormacion();
    
    void setIdMetodologia(int nuevoIdMetodologia);
    int getIdMetodologia();
    
    void setMetodologia(string &nuevaMetodologia);
    string getMetodologia();
    
    void setIdArea(int nuevoIdArea);
    int getIdArea();
    
    void setAreaDeConocimiento(string &areaConocimiento);
    string getAreaDeConocimiento();
    
    void setIdNucleo(int nuevoIdNucleo);
    int getIdNucleo();
    
    void setNucleoBasicoDelConocimientoNbc(string &nuevoNucleoBasicoDelConocimientoNbc);
    string getNucleoBasicoDelConocimientoNbc();
    
    void setIdCineCampoAmplio(int nuevoIdCineCampoAmplio);
    int getIdCineCampoAmplio();
    
    void setDescCineCampoAmplio(string &nuevoDescCineCampoAmplio);
    string getDescCineCampoAmplio();
    
    void setIdCineCampoEspecifico(int nuevoIdCineCampoEspecifico);
    int getIdCineCampoEspecifico();
    
    void setDescCineCampoEspecifico(string &nuevoDescCineCampoEspecifico);
    string getDescCineCampoEspecifico();
    
    void setIdCineCodigoDetallado(int nuevoIdCineCodigoDetallado);
    int getIdCineCodigoDetallado();
    
    void setDescCineCodigoDetallado(string &nuevoDescCineCodigoDetallado);
    string getDescCineCodigoDetallado();
    
    void setCodigoDelDepartamentoPrograma(int nuevoCodigoDelDepartamentoPrograma);
    int getCodigoDelDepartamentoPrograma();
    
    void setDepartamentoDeOfertaDelPrograma(string &nuevoDepartamentoDeOfertaDelPrograma);
    string getDepartamentoDeOfertaDelPrograma();
    
    void setCodigoDelMunicipioPrograma(int nuevoCodigoDelMunicipioPrograma);
    int getCodigoDelMunicipioPrograma();
    
    void setMunicipioDeOfertaDelPrograma(string &nuevoMunicipioDeOfertaDelPrograma);
    string getMunicipioDeOfertaDelPrograma();
    
    void setConsolidado(Consolidado *nuevoConsolidado, int pos);
    Consolidado *getConsolidado(int posicionConsolidado);

    void ProgramaAcademico::agregarConsolidado(Consolidado *nuevoConsolidado);
    float ProgramaAcademico::calcularTasaPromedioGraduacion();
    
    ~ProgramaAcademico();
};

#endif 
