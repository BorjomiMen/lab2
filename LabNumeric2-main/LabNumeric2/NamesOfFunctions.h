#pragma once
#include<vector>
#include <functional>
#include<iostream>
#include<cmath>
using namespace std;


vector<vector<double>> differenceScheme(int n, double mu1, double mu2, double breaking_point, int is_test_task, double* maxDifference, double* maxDiffX);
/*
на вход подаются следующие параметры:
double h - шаг, расстояние между узлами сетки
double n - количество участков сетки
double mu1 - левое граничное условие
double mu2 - правое граничное условие
double breaking_point - точка разрыва
int is_test_task - флажок, показывающий, вычисляем мы в данный момент тестовую задачу или же основную

собирает все результаты воедино,возвращает "таблицу", в каждой строчке которой:
{ xi =i*h - текущая точка, v_with_usual_h[i] - численное значение в этой точке,
	v_with_half_h[2 * i] - численное значение в этой точке, вычисленное с половинным шагом,
	v_minus_v_half_h[i] - модуль разности численного решения в данной точке с обычным шагом и с половинным шагом }
*/
double u_for_test(double x);
/*
возвращает аналитическое решение тестовой задачи в точке х
*/
vector<double> sweepMethod(int n, double mu1, double mu2, double breaking_point, int is_test_task);
/*
на вход подаются следующие параметры:
double h - шаг, расстояние между узлами сетки
double n - количество участков сетки
double mu1 - левое граничное условие
double mu2 - правое граничное условие
double breaking_point - точка разрыва
int is_test_task - флажок, показывающий, вычисляем мы в данный момент тестовую задачу или же основную

функция реализует метод прогонки для решения разностной схемы, возвращает вектор типа vector<double> - решение разностной схемы

основные вычисления происходят именно в этой функции
*/
double d_i(double h, double breaking_point, double x_i_minus_05, double x_i_plus_05, double x_i, int is_test_task);
/*
коэффициент из разностной схемы
*/
double a_i(double h, double breaking_point, double x_i_minus_05, double x_i_minus_1, double x_i, int is_test_task);
/*
коэффициент из разностной схемы
*/
double fi_i(double h, double breaking_point, double x_i_minus_05, double x_i_plus_05, double x_i, int is_test_task);
/*
коэффициент из разностной схемы
*/
double A_i(int i, double h, double breaking_point, int is_test_task);
/*
коэффициент из метода прогонки
*/
double B_i(int i, double h, double breaking_point, int is_test_task);
/*
коэффициент из метода прогонки
*/
double C_i(int i, double h, double breaking_point, int is_test_task);
/*
коэффициент из метода прогонки
*/