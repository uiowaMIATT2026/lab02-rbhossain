Step 1: Create the Data
First I will create the two circle images as ITK files so they have proper medical image metadata like spacing, origin, and direction. 
This is important because the registration needs to work in physical space (mm), not just pixel space.
Step 2: Decide on the Registration
I need a linear transform to match the two circles. To align the centers I need a translation, and to match the diameters I need scaling. 
So I will use a transform that handles both.
For the metric I will use Mean Squares, which is appropriate for images with the same modality.
For the optimizer I have a closed-form solution since I can compute the translation and scale directly from the centroids and diameters. 
So I will initialize the transform at the exact answer rather than running many iterations.
Step 3: Write the Algorithm

1. Read both images
2. Convert index to physical points and also find the center and diameter for each circle 
3. Compute the translation vector as the difference between the two centers
4. Compute the scale factor as the ratio of the two diameters
5. Build the transform using the computed translation and scale
6. Setup the metric and optimizer
7. Resample the moving image into the fixed image space
8. Write the registered output image
9. Report the error after registration

Step 4: Write the Code
Lastly write the code in C++ using ITK.
