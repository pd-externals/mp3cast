/*
vox - a musical real-time vocoder. version 1.0
Copyright (C) 2000  Simon MORLAT (simon.morlat@free.fr)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

double LspDcTable[11] = {
 0,
 0.0955505 , 
 0.144073 , 
 0.23468 , 
 0.329773 , 
 0.42334 , 
 0.503387 , 
 0.602783 , 
 0.679321 , 
 0.77771 , 
 0.845886 
};

double CosineTable[257] = {
 1 , 
 0.999939 , 
 0.999695 , 
 0.999329 , 
 0.998779 , 
 0.998108 , 
 0.997314 , 
 0.996338 , 
 0.995178 , 
 0.993896 , 
 0.992493 , 
 0.990906 , 
 0.989197 , 
 0.987305 , 
 0.985291 , 
 0.983093 , 
 0.980774 , 
 0.978333 , 
 0.975708 , 
 0.972961 , 
 0.970032 , 
 0.96698 , 
 0.963806 , 
 0.960449 , 
 0.95697 , 
 0.953308 , 
 0.949524 , 
 0.945618 , 
 0.941528 , 
 0.937317 , 
 0.932983 , 
 0.928528 , 
 0.923889 , 
 0.919128 , 
 0.914185 , 
 0.90918 , 
 0.903992 , 
 0.898682 , 
 0.89325 , 
 0.887634 , 
 0.881897 , 
 0.876099 , 
 0.870117 , 
 0.863953 , 
 0.857727 , 
 0.851379 , 
 0.844849 , 
 0.838196 , 
 0.831482 , 
 0.824585 , 
 0.817566 , 
 0.810486 , 
 0.803223 , 
 0.795837 , 
 0.78833 , 
 0.780762 , 
 0.77301 , 
 0.765198 , 
 0.757202 , 
 0.749146 , 
 0.740967 , 
 0.732666 , 
 0.724243 , 
 0.715759 , 
 0.707092 , 
 0.698364 , 
 0.689514 , 
 0.680603 , 
 0.67157 , 
 0.662415 , 
 0.653198 , 
 0.64386 , 
 0.634399 , 
 0.624878 , 
 0.615234 , 
 0.60553 , 
 0.595703 , 
 0.585815 , 
 0.575806 , 
 0.565735 , 
 0.555542 , 
 0.545349 , 
 0.534973 , 
 0.524597 , 
 0.514099 , 
 0.50354 , 
 0.49292 , 
 0.482178 , 
 0.471375 , 
 0.46051 , 
 0.449585 , 
 0.438599 , 
 0.427551 , 
 0.416443 , 
 0.405212 , 
 0.393982 , 
 0.38269 , 
 0.371338 , 
 0.359924 , 
 0.348389 , 
 0.336914 , 
 0.325317 , 
 0.31366 , 
 0.302002 , 
 0.290283 , 
 0.278503 , 
 0.266724 , 
 0.254883 , 
 0.242981 , 
 0.231079 , 
 0.219116 , 
 0.207092 , 
 0.195068 , 
 0.183044 , 
 0.170959 , 
 0.158875 , 
 0.146729 , 
 0.134583 , 
 0.122437 , 
 0.110229 , 
 0.0980225 , 
 0.0858154 , 
 0.0735474 , 
 0.0613403 , 
 0.0490723 , 
 0.0368042 , 
 0.0245361 , 
 0.0122681 , 
 0 , 
 -0.0122681 , 
 -0.0245361 , 
 -0.0368042 , 
 -0.0490723 , 
 -0.0613403 , 
 -0.0735474 , 
 -0.0858154 , 
 -0.0980225 , 
 -0.110229 , 
 -0.122437 , 
 -0.134583 , 
 -0.146729 , 
 -0.158875 , 
 -0.170959 , 
 -0.183044 , 
 -0.195068 , 
 -0.207092 , 
 -0.219116 , 
 -0.231079 , 
 -0.242981 , 
 -0.254883 , 
 -0.266724 , 
 -0.278503 , 
 -0.290283 , 
 -0.302002 , 
 -0.31366 , 
 -0.325317 , 
 -0.336914 , 
 -0.348389 , 
 -0.359924 , 
 -0.371338 , 
 -0.38269 , 
 -0.393982 , 
 -0.405212 , 
 -0.416443 , 
 -0.427551 , 
 -0.438599 , 
 -0.449585 , 
 -0.46051 , 
 -0.471375 , 
 -0.482178 , 
 -0.49292 , 
 -0.50354 , 
 -0.514099 , 
 -0.524597 , 
 -0.534973 , 
 -0.545349 , 
 -0.555542 , 
 -0.565735 , 
 -0.575806 , 
 -0.585815 , 
 -0.595703 , 
 -0.60553 , 
 -0.615234 , 
 -0.624878 , 
 -0.634399 , 
 -0.64386 , 
 -0.653198 , 
 -0.662415 , 
 -0.67157 , 
 -0.680603 , 
 -0.689514 , 
 -0.698364 , 
 -0.707092 , 
 -0.715759 , 
 -0.724243 , 
 -0.732666 , 
 -0.740967 , 
 -0.749146 , 
 -0.757202 , 
 -0.765198 , 
 -0.77301 , 
 -0.780762 , 
 -0.78833 , 
 -0.795837 , 
 -0.803223 , 
 -0.810486 , 
 -0.817566 , 
 -0.824585 , 
 -0.831482 , 
 -0.838196 , 
 -0.844849 , 
 -0.851379 , 
 -0.857727 , 
 -0.863953 , 
 -0.870117 , 
 -0.876099 , 
 -0.881897 , 
 -0.887634 , 
 -0.89325 , 
 -0.898682 , 
 -0.903992 , 
 -0.90918 , 
 -0.914185 , 
 -0.919128 , 
 -0.923889 , 
 -0.928528 , 
 -0.932983 , 
 -0.937317 , 
 -0.941528 , 
 -0.945618 , 
 -0.949524 , 
 -0.953308 , 
 -0.95697 , 
 -0.960449 , 
 -0.963806 , 
 -0.96698 , 
 -0.970032 , 
 -0.972961 , 
 -0.975708 , 
 -0.978333 , 
 -0.980774 , 
 -0.983093 , 
 -0.985291 , 
 -0.987305 , 
 -0.989197 , 
 -0.990906 , 
 -0.992493 , 
 -0.993896 , 
 -0.995178 , 
 -0.996338 , 
 -0.997314 , 
 -0.998108 , 
 -0.998779 , 
 -0.999329 , 
 -0.999695 , 
 -0.999939 , 
 -1 
};

double BandExpTable[11] = {
 1,
 0.993988 , 
 0.988037 , 
 0.982117 , 
 0.976227 , 
 0.970367 , 
 0.964539 , 
 0.95874 , 
 0.953003 , 
 0.947266 , 
 0.941589 
};


double HammingWindowTable[128*3]={
5.38469e-16,  6.69307e-05,  0.000267706,  0.000602271,  0.00107054,  0.00167238,  0.00240763,  0.00327611,  0.00427757,  0.00541174,  0.00667833,  0.00807699,  0.00960736,  0.011269,  0.0130615,  0.0149844,  0.0170371,  0.0192191,  0.0215298,  0.0239687,  0.0265349,  0.029228,  0.032047,  0.0349914,  0.0380602,  0.0412527,  0.0445681,  0.0480053,  0.0515636,  0.055242,  0.0590394,  0.0629548,  0.0669873,  0.0711357,  0.0753989,  0.0797758,  0.0842652,  0.0888659,  0.0935766,  0.0983962,  0.103323,  0.108357,  0.113495,  0.118736,  0.12408,  0.129524,  0.135068,  0.140709,  0.146447,  0.152279,  0.158204,  0.164221,  0.170327,  0.176522,  0.182803,  0.18917,  0.195619,  0.20215,  0.208761,  0.21545,  0.222215,  0.229054,  0.235966,  0.242949,  0.25,  0.257118,  0.264302,  0.271548,  0.278856,  0.286222,  0.293646,  0.301126,  0.308658,  0.316242,  0.323875,  0.331555,  0.33928,  0.347048,  0.354858,  0.362706,  0.37059,  0.37851,  0.386462,  0.394444,  0.402455,  0.410492,  0.418552,  0.426635,  0.434737,  0.442857,  0.450991,  0.459139,  0.467298,  0.475466,  0.48364,  0.491819,  0.5,  0.508181,  0.51636,  0.524534,  0.532702,  0.540861,  0.549009,  0.557143,  0.565263,  0.573365,  0.581448,  0.589508,  0.597545,  0.605556,  0.613538,  0.62149,  0.62941,  0.637294,  0.645142,  0.652952,  0.66072,  0.668445,  0.676125,  0.683758,  0.691342,  0.698874,  0.706354,  0.713778,  0.721144,  0.728452,  0.735698,  0.742882,  0.75,  0.757051,  0.764034,  0.770946,  0.777785,  0.78455,  0.791239,  0.79785,  0.804381,  0.81083,  0.817197,  0.823478,  0.829673,  0.835779,  0.841796,  0.847721,  0.853553,  0.859291,  0.864932,  0.870476,  0.87592,  0.881264,  0.886505,  0.891643,  0.896677,  0.901604,  0.906423,  0.911134,  0.915735,  0.920224,  0.924601,  0.928864,  0.933013,  0.937045,  0.940961,  0.944758,  0.948436,  0.951995,  0.955432,  0.958747,  0.96194,  0.965009,  0.967953,  0.970772,  0.973465,  0.976031,  0.97847,  0.980781,  0.982963,  0.985016,  0.986938,  0.988731,  0.990393,  0.991923,  0.993322,  0.994588,  0.995722,  0.996724,  0.997592,  0.998328,  0.998929,  0.999398,  0.999732,  0.999933,  1,  0.999933,  0.999732,  0.999398,  0.998929,  0.998328,  0.997592,  0.996724,  0.995722,  0.994588,  0.993322,  0.991923,  0.990393,  0.988731,  0.986938,  0.985016,  0.982963,  0.980781,  0.97847,  0.976031,  0.973465,  0.970772,  0.967953,  0.965009,  0.96194,  0.958747,  0.955432,  0.951995,  0.948436,  0.944758,  0.940961,  0.937045,  0.933013,  0.928864,  0.924601,  0.920224,  0.915735,  0.911134,  0.906423,  0.901604,  0.896677,  0.891643,  0.886505,  0.881264,  0.87592,  0.870476,  0.864932,  0.859291,  0.853553,  0.847721,  0.841796,  0.835779,  0.829673,  0.823478,  0.817197,  0.81083,  0.804381,  0.79785,  0.791239,  0.78455,  0.777785,  0.770946,  0.764034,  0.757051,  0.75,  0.742882,  0.735698,  0.728452,  0.721144,  0.713778,  0.706354,  0.698874,  0.691342,  0.683758,  0.676125,  0.668445,  0.66072,  0.652952,  0.645142,  0.637294,  0.62941,  0.62149,  0.613538,  0.605556,  0.597545,  0.589508,  0.581448,  0.573365,  0.565263,  0.557143,  0.549009,  0.540861,  0.532702,  0.524534,  0.51636,  0.508181,  0.5,  0.491819,  0.48364,  0.475466,  0.467298,  0.459139,  0.450991,  0.442857,  0.434737,  0.426635,  0.418552,  0.410492,  0.402455,  0.394444,  0.386462,  0.37851,  0.37059,  0.362706,  0.354858,  0.347048,  0.33928,  0.331555,  0.323875,  0.316242,  0.308658,  0.301126,  0.293646,  0.286222,  0.278856,  0.271548,  0.264302,  0.257118,  0.25,  0.242949,  0.235966,  0.229054,  0.222215,  0.21545,  0.208761,  0.20215,  0.195619,  0.18917,  0.182803,  0.176522,  0.170327,  0.164221,  0.158204,  0.152279,  0.146447,  0.140709,  0.135068,  0.129524,  0.12408,  0.118736,  0.113495,  0.108357,  0.103323,  0.0983962,  0.0935766,  0.0888659,  0.0842652,  0.0797758,  0.0753989,  0.0711357,  0.0669873,  0.0629548,  0.0590394,  0.055242,  0.0515636,  0.0480053,  0.0445681,  0.0412527,  0.0380602,  0.0349914,  0.032047,  0.029228,  0.0265349,  0.0239687,  0.0215298,  0.0192191,  0.0170371,  0.0149844,  0.0130615,  0.011269,  0.00960736,  0.00807699,  0.00667833,  0.00541174,  0.00427757,  0.00327611,  0.00240763,  0.00167238,  0.00107054,  0.000602271,  0.000267706,  6.69307e-05,
 };
