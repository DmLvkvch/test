const HtmlWebpackPlugin  = require('html-webpack-plugin');
const CleanWebpackPlugin = require('clean-webpack-plugin');
const FlowWebpackPlugin  = require('flow-webpack-plugin');
const path               = require('path');
module.exports = {
    entry: {
        main:       './server.js',
        lib1:       './public/src/admin.js',
        lib2:       './public/src/jqr.js',
        lib3:       './public/src/Participant.js',
        lib4:       './public/src/participants.js',
        lib5:       './public/src/Picture.js',
        lib6:       './public/src/settings.js',
    },
    output: {
        path:     path.join(__dirname, '/public'),
        filename: './bundle.js'
    },
    module: {
        rules: [{
            test: /\.js$/,
            exclude: /node_modules/,
            use: [{
                loader: 'babel-loader'
            }]
        }, {
            test: /\.css$/,
            exclude: /node_modules/,
            use: [
                'style-loader',
                'css-loader'
            ]
        }]
    }
};
