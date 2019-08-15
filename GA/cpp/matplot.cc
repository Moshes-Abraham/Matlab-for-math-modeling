#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#include <Eigen/Eigen>
#include "/usr/local/MATLAB/R2016b/extern/include/engine.h"
#include <boost/algorithm/string.hpp>

class MatArray
{
public:
    MatArray() : _data(NULL){}
    MatArray(size_t irows, size_t icols){
        resize(irows, icols);
    }
    MatArray(const MatArray &obj){
        if (obj._data){
            _data = mxCreateDoubleMatrix(obj.rows(), obj.cols(), mxREAL);
            memcpy(this->ptr(), obj.ptr(), sizeof(double)*rows()*cols());
        }
        else{
            _data = NULL;
        }
    }
    ~MatArray(){ mxDestroyArray(_data); _data = NULL; }

    inline size_t rows() const { return _data ? mxGetM(_data) : 0; }
    inline size_t cols() const { return _data ? mxGetN(_data) : 0; }
    inline double* ptr() const { return _data ? mxGetPr(_data) : NULL; }

    bool resize(size_t irows, size_t icols){
        if (!_data){
            _data = mxCreateDoubleMatrix(irows, icols, mxREAL);
            return (_data != NULL);
        }
        if (rows() == irows || cols() == icols){
            return true;
        }
        mxDestroyArray(_data);
        _data = mxCreateDoubleMatrix(irows, icols, mxREAL);
        return (_data != NULL);
    }

    int put(Engine *ep, const char* var_name){
        return engPutVariable(ep, var_name, _data);
    }

    template<class EigenMat = Eigen::MatrixXf>
    void copy_from_eigen(const EigenMat &emat){
        if (emat.rows()*emat.cols() == 0){
            mxDestroyArray(_data); _data = NULL;
        }
        resize(emat.rows(), emat.cols());
        for (int c = 0; c < emat.cols(); c++){
            for (int r = 0; r < emat.rows(); r++){
                (*this)[r + c*(int)(emat.rows())] = emat(r, c);
            }
        }
    }
    inline double& operator[](int i){
        return ptr()[i];
    }
private:
    mxArray *_data;
};


class Matlab
{
private:
    Matlab(const Matlab &obj){}
public:
    Matlab(){
        _engine = engOpen(NULL);
        if (!_engine){
            cerr << "failed to open MATLAB engine!" << endl;
        }
        else{
            cout << "MATLAB has been started successfully!" << endl;
        }
    }
    ~Matlab(){
        // if you are testing algorithm, you are encouraged to keep the line below bing committed.
        //engClose(_engine); _engine = NULL;
    }

    // line_spec : "LineStyle" + "Marker" + "Color", e.g. "-or"
    // for line
    // "LineStyle" = {"none", "-", ":", "-."}
    // "LineWidth" = 0.5
    // "Color" = {[0 0.4470 0.7410] (default) | RGB triplet | {y,m,c,r,g,b,w,k} | 'none'}
    // for Marker
    // "Marker" = {"none", "o", "+", "*", ".", "x", "s", "d", "^", "v", ">", "<", 'p', 'h'}
    // "MarkerEdgeColor" = 'auto' (default) | 'none' | RGB triplet | {y,m,c,r,g,b,w,k}
    // "MarkerFaceColor" = 'auto' (default) | 'none' | RGB triplet | {y,m,c,r,g,b,w,k}
    // "MarkerSize" = 6
    template<class TMatX = Eigen::MatrixXf, class TMatY = Eigen::MatrixXf>
    int plot(const TMatX &X, const TMatY &Y,
        string nm0  = "",
        string nm1  = "", string nm2  = "",
        string nm3  = "", string nm4  = "",
        string nm5  = "", string nm6  = "",
        string nm7  = "", string nm8  = "",
        string nm9  = "", string nm10 = "",
        string nm11 = "", string nm12 = "",
        string nm13 = "", string nm14 = ""
        ){
        MatArray MX, MY;
        MX.copy_from_eigen(X); MX.put(_engine, "MX");
        MY.copy_from_eigen(Y); MY.put(_engine, "MY");
        string plot_code = "MX, MY";
        string code;

#define EVL_CODE(_ARG0,_ARG1) code = var_plot_code(nm##_ARG0, nm##_ARG1); if(code != ""){ plot_code += ", " + code;}
        code = var_plot_code(nm0, "");
        if (code != ""){
            plot_code += ", " + code;
            EVL_CODE(1, 2);
            EVL_CODE(3, 4);
            EVL_CODE(5, 6);
            EVL_CODE(7, 8);
            EVL_CODE(9, 10);
            EVL_CODE(11, 12);
            EVL_CODE(13, 14);
        }
        else{
            EVL_CODE(0, 1);
            EVL_CODE(2, 3);
            EVL_CODE(4, 5);
            EVL_CODE(6, 7);
            EVL_CODE(8, 9);
            EVL_CODE(10, 11);
            EVL_CODE(12, 13);
        }
#undef EVL_CODE
        plot_code = "plot(" + plot_code + ");";
        cout << plot_code << endl;
        exec(plot_code);
        return 0;
    }

    // line_spec : "LineStyle" + "Marker" + "Color", e.g. "-or"
    // for line
    // "LineStyle" = {"none", "-", ":", "-."}
    // "LineWidth" = 0.5
    // "Color" = {[0 0.4470 0.7410] (default) | RGB triplet | {y,m,c,r,g,b,w,k} | 'none'}
    // for Marker
    // "Marker" = {"none", "o", "+", "*", ".", "x", "s", "d", "^", "v", ">", "<", 'p', 'h'}
    // "MarkerEdgeColor" = 'auto' (default) | 'none' | RGB triplet | {y,m,c,r,g,b,w,k}
    // "MarkerFaceColor" = 'auto' (default) | 'none' | RGB triplet | {y,m,c,r,g,b,w,k}
    // "MarkerSize" = 6
    template<class TMatX = Eigen::MatrixXf, class TMatY = Eigen::MatrixXf, class TMask = Eigen::MatrixXi>
    int plot_mask(const TMatX &X, const TMatY &Y, const TMask &mask,
        string nm0  = "",
        string nm1  = "", string nm2  = "",
        string nm3  = "", string nm4  = "",
        string nm5  = "", string nm6  = "",
        string nm7  = "", string nm8  = "",
        string nm9  = "", string nm10 = "",
        string nm11 = "", string nm12 = "",
        string nm13 = "", string nm14 = ""
        ){
        MatArray MX, MY, MS;

        MX.copy_from_eigen(X); MX.put(_engine, "MX");
        MY.copy_from_eigen(Y); MY.put(_engine, "MY");
        MS.copy_from_eigen(mask); MS.put(_engine, "MS");
        string plot_code = "MX(MS>0), MY(MS>0)";
        string code;

#define EVL_CODE(_ARG0,_ARG1) code = var_plot_code(nm##_ARG0, nm##_ARG1); if(code != ""){ plot_code += ", " + code;}
        code = var_plot_code(nm0, "");
        if (code != ""){
            plot_code += ", " + code;
            EVL_CODE(1, 2);
            EVL_CODE(3, 4);
            EVL_CODE(5, 6);
            EVL_CODE(7, 8);
            EVL_CODE(9, 10);
            EVL_CODE(11, 12);
            EVL_CODE(13, 14);
        }
        else{
            EVL_CODE(0, 1);
            EVL_CODE(2, 3);
            EVL_CODE(4, 5);
            EVL_CODE(6, 7);
            EVL_CODE(8, 9);
            EVL_CODE(10, 11);
            EVL_CODE(12, 13);
        }
#undef EVL_CODE
        plot_code = "plot(" + plot_code + ");";
        cout << plot_code << endl;
        exec(plot_code);
        return 0;
    }

    string var_plot_code(string nm, string var){
        boost::trim(nm); boost::trim(var);
        if (nm == ""){
            return "";
        }
        string code = "'" + nm + "'";

        if (var == ""){
            return (nm[0] < 'A' || nm[0] > 'Z') ? code : "";
        }
        if (nm == "LineStyle" || nm == "Marker"){ // string
            // 'LineStyle', '-'
            return code + ", '" + var + "'";
        }
        if (nm == "LineWidth" || nm == "MarkerSize"){ // positive number
            // 'LineWidth', 0.5
            return code + ",  " + var;
        }
        if (nm == "Color" || nm == "MarkerEdgeColor" || nm == "MarkerFaceColor"){
            if (var[0] == '['){
                return code + ",  " + var;
            }
            else{
                return code + ", '" + var + "'";
            }
        }
        return "";
    }

    int exec(string cmd){
        return engEvalString(_engine, cmd.c_str());
    }

private:
    Engine *_engine;
};

string rndcolor(){
    string color = "[";
    color += to_string((rand() % 256) / 255.) + ",";
    color += to_string((rand() % 256) / 255.) + ",";
    color += to_string((rand() % 256) / 255.) + "]";
    return color;
}

Matlab mbeng;
int main(int argc, char** argv){

    // random circles
    Eigen::ArrayXXf data;
    data = data.Random(1000, 2);
    //mbeng.exec("figure(1); clf;");
    mbeng.plot(data.col(0), data.col(1), "o", "MarkerFaceColor", "[0,0,0]", "MarkerEdgeColor", "[0,0,0]");
    mbeng.exec("axis tight;");


    // different colors
    int K = 4;
    Eigen::ArrayXXi clid;
    clid = Eigen::abs(clid.Random(1000, 1));
    for (int i = 0; i < clid.rows(); i++){
        clid(i, 0) = clid(i, 0) % K;
    }   
    mbeng.exec("figure(2); clf;");
    for (int k = 0; k < K; k++){
        string colors = rndcolor();
        mbeng.plot_mask(data.col(0), data.col(1), (clid == k), "o", "MarkerFaceColor", colors, "MarkerEdgeColor", colors, "MarkerSize", "5");
        mbeng.exec("hold on;");
    }
    mbeng.exec("hold off;");
    mbeng.exec("axis tight;");

    // plot line
    Eigen::ArrayXf X;
    Eigen::ArrayXf Y;
    X = X.LinSpaced(30,-3.1415926f, 3.1415926f);
    Y = X.sin()*X.cos();
    mbeng.exec("figure(3);");
    mbeng.plot(X, Y, "LineStyle", "-.", "Marker", "o", "MarkerSize", "5", "MarkerFaceColor", "[0,1,0]");
    mbeng.exec("axis tight;");

    getchar();

    return EXIT_SUCCESS;
}
