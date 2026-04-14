I created the test images as ITK .mha files to match medical image format, with proper metadata including spacing, origin, and direction. 
I tested the registration on these two 2D circle images. img1 has a 30mm diameter centered at (50, 50) mm and img2 has a 60mm diameter centered at (200, 200) mm. 
The algorithm computed a translation of (-150, -150) mm and a scale of 0.5, which matched the expected values exactly given the known geometry. 
I applied the affine transform and resampled the moving image, then visually verified the result in 3D Slicer where the registered circle coincided 
exactly with img1. The residual center error was 0 mm, which confirms that the registration is correct.
