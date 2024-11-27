#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include "Image.h"
#include "Worker.h"
using namespace Worker;

int main() {
    // filesystem::create_directory("./output");
    /*---------------------------------------------Part 1 ---------------------------------------------*/
    auto top1 = ReadInImage("input/layer1.tga");
    auto bottom1 = ReadInImage("input/pattern1.tga");

    auto part1 = Multiply(top1, bottom1);
    WriteImageData("./output/part1.tga", part1);

    // if (TestImages("Multiply", "examples/EXAMPLE_part1.tga", part1)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    /*---------------------------------------------Part 2 ---------------------------------------------*/
    auto top2 = ReadInImage("input/layer2.tga");
    auto bottom2 = ReadInImage("input/car.tga");
    auto part2 = Subtract(top2, bottom2);
    WriteImageData("./output/part2.tga", part2);

    // if (TestImages("Subtract", "examples/EXAMPLE_part2.tga", part2)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    // /*---------------------------------------------Part 3 ---------------------------------------------*/
    auto top3Multi = ReadInImage("input/layer1.tga");
    auto bottom3Multi = ReadInImage("input/pattern2.tga");

    auto screen = ReadInImage("input/text.tga");
    auto part3 = Screen(screen, Multiply(top3Multi, bottom3Multi));
    WriteImageData("./output/part3.tga", part3);

    // if (TestImages("Screen", "examples/EXAMPLE_part3.tga", part3)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }


    /*---------------------------------------------Part 4 ---------------------------------------------*/
    auto top4Multi = ReadInImage("input/layer2.tga");
    auto bottom4Multi = ReadInImage("input/circles.tga");
    auto bot4multi = Multiply(top4Multi, bottom4Multi);

    auto top4Sub = ReadInImage("input/pattern2.tga");
    auto part4 = Subtract(top4Sub, bot4multi);
    WriteImageData("./output/part4.tga", part4);

    // if (TestImages("Multiply + Subtract", "examples/EXAMPLE_part4.tga", part4)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    /*---------------------------------------------Part 5 ---------------------------------------------*/
    auto top5 = ReadInImage("input/layer1.tga");
    auto bottom5 = ReadInImage("input/pattern1.tga");
    auto part5 = Overlay(top5, bottom5);
    WriteImageData("./output/part5.tga", part5);

    // if (TestImages("Overlay", "examples/EXAMPLE_part5.tga", part5)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    /*---------------------------------------------Part 6 ---------------------------------------------*/
    auto img6 = ReadInImage("input/car.tga");
    auto part6 = AddGreen(img6);
    WriteImageData("./output/part6.tga", part6);
    //
    // if (TestImages("Add Green", "examples/EXAMPLE_part6.tga", part6)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    /*---------------------------------------------Part 7 ---------------------------------------------*/
    auto img7 = ReadInImage("input/car.tga");
    auto part7 = Scale(img7);
    WriteImageData("./output/part7.tga", part7);

    // if (TestImages("Scale", "examples/EXAMPLE_part7.tga", part7)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    /*---------------------------------------------Part 8 ---------------------------------------------*/
    auto img8 = ReadInImage("input/car.tga");
    auto part8 = SeparateChannel(img8);
    WriteImageData("./output/part8_r.tga", part8[0]);
    WriteImageData("./output/part8_g.tga", part8[1]);
    WriteImageData("./output/part8_b.tga", part8[2]);

    // if (TestImages("Separate Channels", "examples/EXAMPLE_part8_r.tga", part8[0])) {
    //     if (TestImages("Separate Channels", "examples/EXAMPLE_part8_g.tga", part8[1]))
    //         if (TestImages("Separate Channels", "examples/EXAMPLE_part8_b.tga", part8[2])) {
    //             cout << "--------------------------------------------------------------------------------Tests Passed!"
    //                     << endl;
    //         } else
    //             cout << "failure" << endl;
    // }

    /*---------------------------------------------Part 8 ---------------------------------------------*/
    auto img9_r = ReadInImage("input/layer_red.tga");
    auto img9_g = ReadInImage("input/layer_green.tga");
    auto img9_b = ReadInImage("input/layer_blue.tga");
    auto part9 = Combine(img9_r, img9_g, img9_b);
    WriteImageData("./output/part9.tga", part9);


    // if (TestImages("Combine", "examples/EXAMPLE_part9.tga", part9)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    /*---------------------------------------------Part 8 ---------------------------------------------*/
    auto img10 = ReadInImage("input/text2.tga");
    auto part10 = Flip180(img10);
    WriteImageData("./output/part10.tga", part10);

    // if (TestImages("Flip180", "examples/EXAMPLE_part10.tga", part10)) {
    //     cout << "--------------------------------------------------------------------------------Tests Passed!" << endl;
    // }

    return 0;
}
