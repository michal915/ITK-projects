
#include <iostream>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

constexpr unsigned int dimension {2};
using Pixel   = unsigned char;
using Image   = itk::Image <Pixel, dimension>;
using Reader  = itk::ImageFileReader<Image>;
using Writer  = itk::ImageFileWriter<Image>;


/*
 * First test project using ITK library
 *
 */
int main(int argc, char* argv[])
{
  std::cout << "Hello ITK World !!!!" << std::endl;

  auto reader = Reader::New();
  auto writer = Writer::New();

  writer->SetInput(reader->GetOutput());
  writer->Update();

  return 0;
}
