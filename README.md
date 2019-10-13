# IPGaussianMixtureModels
Image Processing using GMMs for AUV team.

### Brief explanation of the codes
>main.cpp 
>  -creates histogram for rgb values and a graph for which we would like to create GMM.

>gmm_plot
>  -plots the probability from the GMM for specific channnel
  
>test.cpp
>  -creates a list for which we would like to create histogram (find probability)
  
>gmm_eg.cpp
> -example mlpack code
  
### Usage of mlpack
 
For training a gmm: 
```sh
$mlpack_gmm_train
```
For finding the probabilities
```sh
$mlpack_gmm_probability
```
  
  
